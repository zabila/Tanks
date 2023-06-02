#include "CTankFactory.h"

#include <memory>

#include "CEnemyTank.h"
#include "CPlayerTank.h"

std::shared_ptr<ITank> CTankFactory::createTank(ETankType type, Point position)
{
    switch (type) {
    case ETankType::PLAYER:
        return std::make_shared<CPlayerTank>(nullptr, position);
    case ETankType::LIGHT:
        return std::make_shared<CEnemyTank>(nullptr, position);
    case ETankType::MEDIUM:
        return std::make_shared<CEnemyTank>(nullptr, position);
    case ETankType::HEAVY:
        return std::make_shared<CEnemyTank>(nullptr, position);
    }
    return nullptr;
}
