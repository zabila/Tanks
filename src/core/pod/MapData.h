#pragma once

#include <optional>

struct MapData
{
    int width;
    int height;

    bool contains(const Point& p) const { return p.x >= 0 && p.x <= width && p.y >= 0 && p.y <= height; }

    friend std::ostream& operator<<(std::ostream& os, const MapData& map_range)
    {
        os << "width: " << map_range.width << " height: " << map_range.height;
        return os;
    }
};
using MapDataOpt = std::optional<MapData>;
