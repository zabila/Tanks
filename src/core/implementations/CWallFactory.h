#pragma once

#include <memory>

#include "interfaces/IWallFactory.h"
#include "pod/MapRange.h"

class CWallFactory final : public IWallFactory
{
public:
    std::shared_ptr<IWall> createWall(EWallsType type, const Point &position, const MapRange &map_range) override;
};