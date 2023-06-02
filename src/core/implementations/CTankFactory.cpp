#include "CTankFactory.h"

#include <memory>

#include "CTank.h"

std::shared_ptr<ITank> CTankFactory::createTank(ETankType type, const Point &position, const MapRange &map_range)
{
    switch (type) {
    case ETankType::PLAYER:
        return std::make_shared<CTank>(nullptr, position, map_range);
    case ETankType::LIGHT:
        return std::make_shared<CTank>(nullptr, position, map_range);
    case ETankType::MEDIUM:
        return std::make_shared<CTank>(nullptr, position, map_range);
    case ETankType::HEAVY:
        return std::make_shared<CTank>(nullptr, position, map_range);
    default:
        break;
    }
    return nullptr;
}
