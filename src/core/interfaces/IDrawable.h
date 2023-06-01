#pragma once

#include <QObject>

#include "pod/Point.h"

class IDrawable
{
public:
    virtual ~IDrawable() = default;
    virtual void draw() = 0;
    virtual PointWrapper *position() const = 0;
};

Q_DECLARE_INTERFACE(IDrawable, "com.example.IDrawable")
