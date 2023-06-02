#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Logger.h"
#include "managers/CControllerManager.h"

int main(int argc, char *argv[])
{
    g_logger = new LoggerImpl("log.txt");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    CControllerManager controllerManager;
    controllerManager.RegisterMetaTypes();
    controllerManager.initializeAll(&engine);
    engine.addImportPath(":/");
    engine.load(QUrl(QStringLiteral("qrc:main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto ret = app.exec();

    delete g_logger;
    g_logger = nullptr;

    return ret;
}
