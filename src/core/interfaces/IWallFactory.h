#pragma once

#include <memory>

#include "IWall.h"
#include "pod/MapRange.h"

class IWallFactory
{
public:
    enum class EWallsType {
        BRICK,
        CONCRETE,
    };

    virtual std::shared_ptr<IWall> createWall(EWallsType type, const Point &position, const MapRange &map_range) = 0;
};