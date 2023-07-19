#pragma once

#include <QQmlApplicationEngine>

#include "Engine/CGameEngine.h"
#include "interfaces/IController.h"

#include <memory>
#include <vector>

class CControllerManager
{
public:
    explicit CControllerManager(QQmlApplicationEngine* engine);
    ~CControllerManager() = default;

    void initializeAll(QQmlApplicationEngine* engine);
    void RegisterMetaTypes();

private:
    void init(QQmlApplicationEngine* engine);

    std::shared_ptr<CGameEngine> gameEngine;
    std::vector<std::unique_ptr<IController>> controllers_;
};
