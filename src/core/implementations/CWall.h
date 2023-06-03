#pragma once

#include <memory>

#include <QObject>

#include "interfaces/IWall.h"
#include "pod/MapRange.h"
#include "pod/Point.h"

class CWall final : public QObject, public IWall
{
    Q_OBJECT
    Q_INTERFACES(IWall IDrawable)
    Q_PROPERTY(PointWrapper *position READ position NOTIFY positionChanged)
public:
    explicit CWall(QObject *parent = nullptr, const Point &position = {}, const MapRange &map_range = {}) noexcept;
    ~CWall() override = default;

    PointWrapper *position() const override;

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE bool isDestroyable() const override;
    
signals:
    void positionChanged();

private:
    std::unique_ptr<PointWrapper> position_;
    MapRange map_range_;
    bool isDestroyable_;
    bool isDrawn_;
};
