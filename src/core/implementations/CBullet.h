#pragma once

#include <memory>

#include <QObject>

#include "Pod/Point.h"
#include "interfaces/IBullet.h"
#include "interfaces/IMovable.h"

class CBullet final : public QObject, public IBullet
{
    Q_OBJECT
    Q_INTERFACES(IBullet IDrawable IMovable)
public:
    explicit CBullet(QObject *parent = nullptr, const Point &position = {}) noexcept;
    ~CBullet() override = default;

    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move(MyEnum::Direction) override;
    Q_INVOKABLE PointWrapper *position() const override;
    Q_INVOKABLE int speed() const override;

private:
    std::unique_ptr<PointWrapper> position_;
    int speed_;
    bool isDrawn_;
};
