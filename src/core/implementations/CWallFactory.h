#pragma once

#include <memory>

#include "interfaces/IWallFactory.h"

class CWallFactory : public IWallFactory
{
public:
    std::unique_ptr<IWall> createWall(EWallsType type) override;
};