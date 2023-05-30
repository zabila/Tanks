#pragma once

#include <QObject>

#include "interfaces/IWall.h"

class CConcreteWall : public QObject, public IWall
{
    Q_OBJECT
    Q_INTERFACES(IWall IDrawable)
public:
    explicit CConcreteWall();

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE bool isDestroyble() const override;
};
