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

    virtual std::shared_ptr<IWall> createWall(EWallsType type, Point position) = 0;
};