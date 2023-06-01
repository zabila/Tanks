#pragma once

#include <QObject>

#include "interfaces/IDrawable.h"
#include "interfaces/IMovable.h"

class ITank : public IDrawable, public IMovable
{
public:
    ~ITank() override = default;
    virtual void shoot() = 0;
};

Q_DECLARE_INTERFACE(ITank, "com.example.ITank")
