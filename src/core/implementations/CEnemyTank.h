#pragma once

#include <memory>

#include <QObject>

#include "interfaces/ITank.h"
#include "pod/Enums.h"
#include "pod/Point.h"

class CEmemyTank final : public QObject, public ITank
{
    Q_OBJECT
    Q_INTERFACES(ITank IDrawable IMovable)
    Q_PROPERTY(PointWrapper *position READ position NOTIFY positionChanged)
    Q_PROPERTY(int speed READ speed CONSTANT)
public:
    explicit CEmemyTank(QObject *parent = nullptr, const Point &position = {}) noexcept;
    ~CEmemyTank() override = default;

    PointWrapper *position() const override;
    int speed() const override;

    Q_INVOKABLE void shoot() override;
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void move(MyEnum::Direction direction) override;

signals:
    void positionChanged();

private:
    std::unique_ptr<PointWrapper> position_;
    int speed_;
    bool isDrawn_;
};
