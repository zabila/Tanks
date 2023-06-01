#include "CWallFactory.h"

#include "CBrickWall.h"
#include "CConcreteWall.h"

std::shared_ptr<IWall> CWallFactory::createWall(EWallsType type, Point position)
{
    switch (type) {
    case EWallsType::BRICK:
        return std::make_shared<CBrickWall>(nullptr, position);
    case EWallsType::CONCRETE:
        return std::make_shared<CConcreteWall>(nullptr, position);
    default:
        return nullptr;
    }
}
