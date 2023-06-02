#pragma once

#include <memory>

#include "ITank.h"
#include "pod/MapRange.h"

class ITankFactory
{
public:
    enum class ETankType { PLAYER, LIGHT, MEDIUM, HEAVY };

    virtual std::shared_ptr<ITank> createTank(ETankType type, const Point &position, const MapRange &map_range) = 0;
};
