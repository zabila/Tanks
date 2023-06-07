#include "CTank.h"

#include "Engine/CGameEngine.h"
#include "Logger.h"
#include "Logger/LogStream.h"
#include "pod/Point.h"

CTank::CTank(CGameEngine* gameEngine, const Point& position, const TankData& data)
    : QObject(nullptr)
    , id_(getId())
    , data_(data)
    , gameEngine_(gameEngine)
    , position_(std::make_unique<PointWrapper>(position, this))
    , speed_(2)
    , is_drawn_(false)
{}

void CTank::draw()
{
    if (is_drawn_)
        return;
    is_drawn_ = true;
}

void CTank::move(MyEnum::Direction direction)
{
    auto save_position = *position_;
    switch (direction) {
    case MyEnum::Direction::UP:
        position_->setY(position_->y() - speed_);
        break;
    case MyEnum::Direction::DOWN:
        position_->setY(position_->y() + speed_);
        break;
    case MyEnum::Direction::LEFT:
        position_->setX(position_->x() - speed_);
        break;
    case MyEnum::Direction::RIGHT:
        position_->setX(position_->x() + speed_);
        break;
    }

    if (!gameEngine_->inRangOfMap(position_->value())) {
        *position_ = save_position;
        Log(WARNING) << "Tank is out of map";
        return;
    }

    auto [collide_object, is_collide] = gameEngine_->checkingCollisions(this);
    if (is_collide) {
        *position_ = save_position;
        Log(WARNING) << "Tank is collide with " << collide_object->id();

        gameEngine_->detroitObject(collide_object);
        gameEngine_->updateEnemyTanks();
    }

    onPositionChanged();
}

void CTank::onPositionChanged()
{
    is_drawn_ = false;
    draw();
    emit positionChanged();
}

void CTank::shoot()
{
    Log(INFO) << "Player tank is shoot";
}

PointWrapper* CTank::position() const
{
    return position_.get();
}

int CTank::speed() const
{
    return speed_;
}

bool CTank::isCollide(IDrawable* drawn_object) const
{
    const Point& topLeft = position_->value();
    const Point& drawn_point = drawn_object->position()->value();
    const int objectSize = data_.size;

    const bool isCollideX = (topLeft.x < drawn_point.x + objectSize) && (drawn_point.x < topLeft.x + objectSize);
    const bool isCollideY = (topLeft.y < drawn_point.y + objectSize) && (drawn_point.y < topLeft.y + objectSize);

    return isCollideX && isCollideY;
}

int CTank::id() const
{
    return id_;
}
int CTank::size() const
{
    return data_.size;
}
