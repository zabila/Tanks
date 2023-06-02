#include "CEnemyTank.h"
#include "Logger.h"

#include "interfaces/IMovable.h"

CEnemyTank::CEnemyTank(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , speed_(1)
    , isDrawn_(false)
{}

void CEnemyTank::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Enemy tank is drawn " << position_.get();
}
void CEnemyTank::move(MyEnum::Direction direction)
{
    Log(INFO) << "Player tank is moved to " << toString(direction);
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
    isDrawn_ = false;
    draw();
}
PointWrapper *CEnemyTank::position() const
{
    return position_.get();
}
int CEnemyTank::speed() const
{
    return speed_;
}

void CEnemyTank::shoot()
{
    Log(INFO) << "Enemy tank is shoot";
}
