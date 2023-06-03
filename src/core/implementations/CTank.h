#pragma once

#include <memory>

#include <QObject>

#include "interfaces/ITank.h"
#include "pod/Enums.h"
#include "pod/MapRange.h"
#include "pod/Point.h"

class CTank : public QObject, public ITank
{
    Q_OBJECT
    Q_INTERFACES(ITank IDrawable IMovable)
    Q_PROPERTY(PointWrapper *position READ position NOTIFY positionChanged)
    Q_PROPERTY(int speed READ speed CONSTANT)
public:
    explicit CTank(QObject *parent = nullptr, const Point &position = {}, const MapRange &map_range = {}) noexcept;
    ~CTank() override = default;

    PointWrapper *position() const override;
    int speed() const override;
    bool isCollide(IDrawable *drawn_object) const override;

    Q_INVOKABLE void shoot() override;
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move(MyEnum::Direction direction) override;

signals:
    void positionChanged();

private:
    std::unique_ptr<PointWrapper> position_;
    MapRange map_range_;
    int speed_;
    bool isDrawn_;
};
