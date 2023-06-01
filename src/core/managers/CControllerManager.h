#pragma once

#include <QQmlApplicationEngine>

#include "controllers/CGameController.h"

class CControllerManager
{
public:
    explicit CControllerManager();

    void initializeAll(QQmlApplicationEngine *engine);

private:
    CGameController gameController;
};
