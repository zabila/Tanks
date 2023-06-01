#pragma once

#include <QObject>

#include "interfaces/IDrawable.h"
#include "interfaces/IMovable.h"

class IBullet : public IDrawable, public IMovable
{
public:
    ~IBullet() override = default;
    virtual int damage() const = 0;
};

Q_DECLARE_INTERFACE(IBullet, "com.example.IBullet")