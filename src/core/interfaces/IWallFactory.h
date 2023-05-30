#pragma once

#include <memory>

#include "IWall.h"

class IWallFactory
{
public:
    enum class EWallsType {
        BRICK,
        CONCRETE,
    };

    virtual std::unique_ptr<IWall> createWall(EWallsType type) = 0;
};