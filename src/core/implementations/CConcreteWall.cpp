#include "CConcreteWall.h"
#include "Logger.h"

CConcreteWall::CConcreteWall(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , isDestroyble_(false)
    , isDrawn_(false)
{}

void CConcreteWall::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Enemy tank is drawn " << position_.get();
}

bool CConcreteWall::isDestroyable() const
{
    return isDestroyble_;
}

PointWrapper *CConcreteWall::position() const
{
    return position_.get();
}
