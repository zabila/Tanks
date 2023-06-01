#pragma once

#include <memory>

#include "ITank.h"

class ITankFactory
{
public:
    enum class ETankType { PLAYER, LIGHT, MEDIUM, HEAVY };

    virtual std::shared_ptr<ITank> createTank(ETankType type, Point position) = 0;
};
