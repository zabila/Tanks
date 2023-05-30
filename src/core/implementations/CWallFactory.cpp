#include "CWallFactory.h"

#include "CBrickWall.h"
#include "CConcreteWall.h"

std::unique_ptr<IWall> CWallFactory::createWall(EWallsType type)
{
    switch (type) {
    case EWallsType::BRICK:
        return std::make_unique<CBrickWall>();
    case EWallsType::CONCRETE:
        return std::make_unique<CConcreteWall>();
    default:
        return nullptr;
    }
}
