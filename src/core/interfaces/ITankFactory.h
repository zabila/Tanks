#pragma once

#include <memory>

#include "ITank.h"

class ITankFactory
{
public:
    enum class ETankType { PLAYER, LIGHT, MEDIUM, HEAVY };
    
    virtual std::unique_ptr<ITank> createTank(ETankType type) = 0;
};