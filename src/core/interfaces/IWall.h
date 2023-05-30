#pragma once

#include <QObject>

#include "interfaces/IDrawable.h"

#include "pod/Point.h"

class IWall : public IDrawable
{
public:
    ~IWall() override = default;
    virtual bool isDestroyble() const = 0;

protected:
    bool isDestroyble_{};
    Point position_{};
};

Q_DECLARE_INTERFACE(IWall, "com.example.IWall")
