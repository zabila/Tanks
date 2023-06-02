#pragma once

#include <QQmlApplicationEngine>

#include "CGameManager.h"
#include "interfaces/IController.h"

#include <memory>
#include <vector>

class CControllerManager
{
public:
    explicit CControllerManager();
    ~CControllerManager() = default;

    void initializeAll(QQmlApplicationEngine *engine);
    void RegisterMetaTypes();

private:
    void init();

    std::shared_ptr<CGameManager> gameManager_;
    std::vector<std::unique_ptr<IController>> controllers_;
};
