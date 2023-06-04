#pragma once

#include <QObject>

#include "pod/Point.h"

class IDrawable
{
public:
    virtual ~IDrawable() = default;
    virtual int id() const = 0;
    virtual void draw() = 0;
    virtual PointWrapper *position() const = 0;
};

static int getId()
{
    static int id = 0;
    return ++id;
}

Q_DECLARE_INTERFACE(IDrawable, "com.example.IDrawable")
