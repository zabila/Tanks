#include "CBullet.h"
#include "Logger.h"

CBullet::CBullet(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , speed_(1)
    , isDrawn_(false)
{}

void CBullet::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Enemy tank is drawn " << position_.get();
}

void CBullet::move(MyEnum::Direction direction)
{
    isDrawn_ = false;
    Log(INFO) << "Bullet is moved" << toString(direction);
}

PointWrapper *CBullet::position() const
{
    return position_.get();
}

int CBullet::speed() const
{
    return speed_;
}
