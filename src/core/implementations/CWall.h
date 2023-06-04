#pragma once

#include <memory>

#include <QObject>

#include "interfaces/IWall.h"
#include "pod/Point.h"

class CGameEngine;
class CWall : public QObject, public IWall
{
    Q_OBJECT
    Q_INTERFACES(IWall IDrawable)
    Q_PROPERTY(PointWrapper* position READ position NOTIFY positionChanged)
public:
    explicit CWall(CGameEngine* gameEngine, const Point& position);
    ~CWall() override = default;

    int id() const override;
    PointWrapper* position() const override;

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE bool isDestroyable() const override;

signals:
    void positionChanged();

private:
    const int id_;
    CGameEngine* gameEngine_;
    std::unique_ptr<PointWrapper> position_;
    bool isDestroyable_;
    bool isDrawn_;
};
