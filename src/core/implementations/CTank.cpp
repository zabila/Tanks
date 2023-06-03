#include "CTank.h"
#include "Logger.h"
#include "pod/Point.h"

CTank::CTank(QObject *parent, const Point &position, const MapRange &map_range) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , map_range_(map_range)
    , speed_(5)
    , isDrawn_(false)
{}

void CTank::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Tank is drawn " << position_.get();
}

void CTank::move(MyEnum::Direction direction)
{
    if (!map_range_.contains(position_->value())) {
        Log(WARNING) << "Tank is out of map range";
        return;
    }

    auto new_position = *position_;
    switch (direction) {
    case MyEnum::Direction::UP:
        new_position.setY(position_->y() - speed_);
        break;
    case MyEnum::Direction::DOWN:
        new_position.setY(position_->y() + speed_);
        break;
    case MyEnum::Direction::LEFT:
        new_position.setX(position_->x() - speed_);
        break;
    case MyEnum::Direction::RIGHT:
        new_position.setX(position_->x() + speed_);
        break;
    }

    if (!map_range_.contains(new_position.value())) {
        Log(WARNING) << "Tank would move out of map range";
        return;
    }
    *position_ = new_position;

    isDrawn_ = false;
    draw();
    emit positionChanged();
}

void CTank::shoot()
{
    Log(INFO) << "Player tank is shoot";
}

PointWrapper *CTank::position() const
{
    return position_.get();
}

int CTank::speed() const
{
    return speed_;
}

bool CTank::isCollide(IDrawable *drawn_object) const
{
    Point topLeft = position_->value();
    Point drawn_point = drawn_object->position()->value();
    int length = 30;

    return topLeft.x < drawn_point.x + length && drawn_point.x < topLeft.x + length
           && topLeft.y < drawn_point.y + length && drawn_point.y < topLeft.y + length;
}