#include "CBrickWall.h"
#include "Logger.h"

CBrickWall::CBrickWall(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , isDestroyble_(true)
    , isDrawn_(false)
{}

void CBrickWall::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Enemy tank is drawn " << position_.get();
}

bool CBrickWall::isDestroyble() const
{
    return isDestroyble_;
}

PointWrapper *CBrickWall::position() const
{
    return position_.get();
    ;
}
