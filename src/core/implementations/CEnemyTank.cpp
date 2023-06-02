#include "CEnemyTank.h"
#include "Logger.h"

#include "interfaces/IMovable.h"

CEmemyTank::CEmemyTank(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , speed_(1)
    , isDrawn_(false)
{}

void CEmemyTank::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Enemy tank is drawn " << position_.get();
}
void CEmemyTank::move(MyEnum::Direction direction)
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
PointWrapper *CEmemyTank::position() const
{
    return position_.get();
}
int CEmemyTank::speed() const
{
    return speed_;
}

void CEmemyTank::shoot()
{
    Log(INFO) << "Enemy tank is shooted";
}
