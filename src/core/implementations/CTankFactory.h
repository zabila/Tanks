#pragma once

#include <memory>

#include "interfaces/ITankFactory.h"

class CTankFactory final : public ITankFactory
{
public:
    std::shared_ptr<ITank> createTank(ETankType type, const Point &position, const MapRange &map_range) override;
};