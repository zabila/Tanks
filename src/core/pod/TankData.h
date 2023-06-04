#pragma once

#include <optional>
#include <string>

#include "Logger.h"

struct TankData
{
    int size;
    std::string imagePath;

    friend std::ostream& operator<<(std::ostream& os, const TankData& tank_data)
    {
        os << "size: " << tank_data.size << " imagePath: " << tank_data.imagePath;
        return os;
    }
};
using TankDataOpt = std::optional<TankData>;