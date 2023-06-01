#pragma once

#include <QObject>

#include "IDrawable.h"

class IBase : public IDrawable
{
public:
    virtual ~IBase() = default;
    virtual void initialize() = 0;
};

Q_DECLARE_INTERFACE(IBase, "com.example.IBase")
