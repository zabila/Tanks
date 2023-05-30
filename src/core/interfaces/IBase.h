#pragma once

#include "pod/Point.h"
#include <QObject>

class IBase
{
public:
    virtual ~IBase() = default;
    virtual void initialize() = 0;

protected:
    Point position_{};
};

Q_DECLARE_INTERFACE(IBase, "com.example.IBase")
