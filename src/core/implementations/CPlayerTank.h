#pragma once

#include <memory>

#include <QObject>

#include "interfaces/ITank.h"
#include "pod/Point.h"
#include "pod/Enums.h"

class CPlayerTank : public QObject, public ITank
{
    Q_OBJECT
    Q_INTERFACES(ITank IDrawable IMovable)
    Q_PROPERTY(PointWrapper *position READ position CONSTANT)
    Q_PROPERTY(int speed READ speed CONSTANT)
public:
    explicit CPlayerTank(QObject *parent = nullptr, const Point &position = {}) noexcept;
    ~CPlayerTank() override = default;

    PointWrapper *position() const override;
    int speed() const override;

    Q_INVOKABLE void shoot() override;
    Q_INVOKABLE void draw() override;

public slots:
    void move(MyEnum::Direction direction) override;

private:
    std::unique_ptr<PointWrapper> position_;
    int speed_;
    bool isDrawn_;
};
