#pragma once

#include <QObject>

#include "interfaces/IWall.h"

class CBrickWall : public QObject, public IWall
{
    Q_OBJECT
    Q_INTERFACES(IWall IDrawable)
public:
    explicit CBrickWall();

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE bool isDestroyble() const override;
};
