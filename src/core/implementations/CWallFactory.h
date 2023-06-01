#pragma once

#include <memory>

#include "interfaces/IWallFactory.h"

class CWallFactory final : public IWallFactory
{
public:
    std::shared_ptr<IWall> createWall(EWallsType type, Point position) override;
};