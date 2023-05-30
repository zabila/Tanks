#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Logger.h"
#include "managers/CGameManager.h"

int main(int argc, char *argv[])
{
    g_logger = new LoggerImpl("log.txt");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    CGameManager gameManager;
    auto *context = engine.rootContext();
    context->setContextProperty("gameManager", &gameManager);

    engine.load(QUrl(QStringLiteral("qrc:src/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto ret = app.exec();

    delete g_logger;
    g_logger = nullptr;

    return 0;
}
