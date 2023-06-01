#pragma once

#include <memory>

#include "interfaces/ITankFactory.h"

class CTankFactory final : public ITankFactory
{
public:
    std::shared_ptr<ITank> createTank(ETankType type, Point position) override;
};