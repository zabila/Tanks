#pragma once

#include <memory>

#include <QObject>

#include "pod/Point.h"
#include "interfaces/IBullet.h"

class CGameEngine;
class CBullet : public QObject, public IBullet
{
    Q_OBJECT
    Q_INTERFACES(IBullet IDrawable IMovable)
public:
    explicit CBullet(CGameEngine* gameEngine, const Point& position);
    ~CBullet() override = default;

    int id() const override;
    MyEnum::ObjectType type() const override;

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move(MyEnum::Direction) override;
    Q_INVOKABLE PointWrapper* position() const override;
    Q_INVOKABLE int speed() const override;

private:
    int id_;
    CGameEngine* gameEngine_;
    std::unique_ptr<PointWrapper> position_;
    int speed_;
    bool isDrawn_;
};
