#pragma once

#include <QObject>

#include "interfaces/IDrawable.h"
#include "interfaces/IMovable.h"

class ITank : public IDrawable, public IMovable
{
public:
    virtual ~ITank() = default;
    virtual void shoot() = 0;

protected:
    int health_{};
};

Q_DECLARE_INTERFACE(ITank, "com.example.ITank")