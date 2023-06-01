#include "CControllerManager.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

CControllerManager::CControllerManager()
    : gameController()
{}

void CControllerManager::initializeAll(QQmlApplicationEngine *engine)
{
    gameController.initialize(engine);
}
