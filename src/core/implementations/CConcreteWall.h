#pragma once

#include <memory>

#include <QObject>

#include "interfaces/IWall.h"
#include "pod/Point.h"

class CConcreteWall final : public QObject, public IWall
{
    Q_OBJECT
    Q_INTERFACES(IWall IDrawable)
public:
    explicit CConcreteWall(QObject *parent = nullptr, const Point &position = {}) noexcept;
    ~CConcreteWall() override = default;

    Q_INVOKABLE PointWrapper *position() const override;
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE bool isDestroyble() const override;

private:
    std::unique_ptr<PointWrapper> position_;
    bool isDestroyble_;
    bool isDrawn_;
};
