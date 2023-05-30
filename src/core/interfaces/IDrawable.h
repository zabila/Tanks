#pragma once

#include <QObject>

class IDrawable
{
public:
    virtual ~IDrawable() = default;
    virtual void draw() = 0;
};

Q_DECLARE_INTERFACE(IDrawable, "com.example.IDrawable")