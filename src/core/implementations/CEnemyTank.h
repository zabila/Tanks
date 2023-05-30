#pragma once

#include <QObject>

#include "interfaces/ITank.h"

class CEmemyTank : public QObject, public ITank
{
    Q_OBJECT
    Q_INTERFACES(ITank IDrawable IMovable)
public:
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move() override;
    Q_INVOKABLE void shoot() override;
};