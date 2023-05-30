#pragma once

#include "interfaces/ITankFactory.h"

class CTankFactory : public ITankFactory
{
public:
    std::unique_ptr<ITank> createTank(ETankType type) override;
};