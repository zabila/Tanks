#pragma once

#include <QObject>

#include "interfaces/IBullet.h"

class CBullet : public QObject, public IBullet
{
    Q_OBJECT
    Q_INTERFACES(IBullet IDrawable IMovable)
public:
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move() override;
};