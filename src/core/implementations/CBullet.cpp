#include "CBullet.h"

#include "Engine/CGameEngine.h"
#include "Logger.h"

CBullet::CBullet(CGameEngine* gameEngine, const Point& position)
    : QObject(nullptr)
    , id_(getId())
    , gameEngine_(gameEngine)
    , position_(std::make_unique<PointWrapper>(position, this))
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

PointWrapper* CBullet::position() const
{
    return position_.get();
}

int CBullet::speed() const
{
    return speed_;
}
int CBullet::id() const
{
    return id_;
}
MyEnum::ObjectType CBullet::type() const
{
    return MyEnum::BULLET;
}
