#include "CWallFactory.h"

#include "CWall.h"
#include "pod/MapRange.h"

std::shared_ptr<IWall> CWallFactory::createWall(EWallsType type, const Point &position, const MapRange &map_range)
{
    switch (type) {
    case EWallsType::BRICK:
        return std::make_shared<CWall>(nullptr, position, map_range);
    case EWallsType::CONCRETE:
        return std::make_shared<CWall>(nullptr, position, map_range);
    default:
        return nullptr;
    }
}
