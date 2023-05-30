#pragma once

#include <QObject>

#include "interfaces/IBase.h"
#include "interfaces/IDrawable.h"

#include "pod/Point.h"

class CBase : public QObject, public IBase, public IDrawable
{
    Q_OBJECT
    Q_INTERFACES(IBase IDrawable)
public:
    Q_INVOKABLE void draw() override;
    Q_INVOKABLE void initialize() override;
};