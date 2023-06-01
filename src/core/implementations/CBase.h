#pragma once

#include <memory>

#include <QObject>

#include "interfaces/IBase.h"

class CBase final : public QObject, public IBase
{
    Q_OBJECT
    Q_INTERFACES(IBase IDrawable)
public:
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void initialize() override;
    Q_INVOKABLE PointWrapper *position() const override;

private:
    std::unique_ptr<PointWrapper> position_;
    bool isDrawn_;
};
