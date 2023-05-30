#include "CTankFactory.h"

#include <memory>

#include "CEnemyTank.h"
#include "CPlayerTank.h"

std::unique_ptr<ITank> CTankFactory::createTank(ETankType type)
{
    switch (type) {
    case ETankType::PLAYER:
        return std::make_unique<CPlayerTank>();
    case ETankType::LIGHT:
        return std::make_unique<CEmemyTank>();
    case ETankType::MEDIUM:
        return std::make_unique<CEmemyTank>();
    case ETankType::HEAVY:
        return std::make_unique<CEmemyTank>();
    }
    return nullptr;
}
