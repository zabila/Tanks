#include "CWall.h"
#include "Logger.h"

CWall::CWall(QObject *parent, const Point &position, const MapRange &map_range) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , map_range_(map_range)
    , isDestroyable_(true)
    , isDrawn_(false)
{}

void CWall::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Wall tank is drawn " << position_.get();
}

bool CWall::isDestroyable() const
{
    return isDestroyable_;
}

PointWrapper *CWall::position() const
{
    return position_.get();
}
