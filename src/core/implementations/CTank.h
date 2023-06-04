#pragma once

#include <memory>

#include <QObject>
#include <qobject.h>

#include "interfaces/ITank.h"
#include "pod/Enums.h"
#include "pod/MapData.h"
#include "pod/Point.h"
#include "pod/TankData.h"

class CGameEngine;
class CTank : public QObject, public ITank
{
    Q_OBJECT
    Q_INTERFACES(ITank IDrawable IMovable)
    Q_PROPERTY(PointWrapper* position READ position NOTIFY positionChanged)
    Q_PROPERTY(int speed READ speed CONSTANT)
    Q_PROPERTY(int size READ size CONSTANT)
public:
    explicit CTank(CGameEngine* gameEngine, const Point& position, const TankData& data);
    ~CTank() override = default;

    int id() const override;
    PointWrapper* position() const override;
    int speed() const override;
    bool isCollide(IDrawable* drawn_object) const override;

    Q_INVOKABLE void shoot() override;
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move(MyEnum::Direction direction) override;

    int size() const;

signals:
    void positionChanged();

private:
    void onPositionChanged();

    const int id_;
    TankData data_;
    CGameEngine* gameEngine_;
    std::unique_ptr<PointWrapper> position_;
    int speed_;
    bool is_drawn_;
};
