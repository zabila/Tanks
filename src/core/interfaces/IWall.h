#pragma once

#include <QObject>

#include "interfaces/IDrawable.h"

class IWall : public IDrawable
{
public:
    ~IWall() override = default;
    virtual bool isDestroyble() const = 0;
};

Q_DECLARE_INTERFACE(IWall, "com.example.IWall")
