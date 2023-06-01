#include "CPlayerTank.h"
#include "Logger.h"

CPlayerTank::CPlayerTank(QObject *parent, const Point &position) noexcept
    : QObject(parent)
    , position_(std::make_unique<PointWrapper>(position, parent))
    , speed_(1)
    , isDrawn_(false)
{
    Log(INFO) << "Player tank is created " << position_.get() << " speed: " << speed_
              << " isDrawn: " << isDrawn_;
}

void CPlayerTank::draw()
{
    if (isDrawn_)
        return;

    isDrawn_ = true;
    Log(INFO) << "Player tank is drawn " << position_.get();
}

void CPlayerTank::move(MyEnum::Direction direction)
{
    Log(INFO) << "Player tank is moved to " << toString(direction);
    switch (direction) {
    case MyEnum::Direction::UP:
        position_->setX(position_->x() + speed_);
        break;
    case MyEnum::Direction::DOWN:
        position_->setY(position_->x() - speed_);
        break;
    case MyEnum::Direction::LEFT:
        position_->setY(position_->y() - speed_);
        break;
    case MyEnum::Direction::RIGHT:
        position_->setY(position_->y() + speed_);
        break;
    }
    isDrawn_ = false;
}

void CPlayerTank::shoot()
{
    Log(INFO) << "Player tank is shooted";
}

PointWrapper *CPlayerTank::position() const
{
    return position_.get();
}

int CPlayerTank::speed() const
{
    return speed_;
}
