#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Logger.h"
#include "managers/CControllerManager.h"

int main(int argc, char *argv[])
{
    g_logger = new LoggerImpl("log.txt");

    QGuiApplication app(argc, argv);

    qRegisterMetaType<PointWrapper>("PointWrapper");
    qmlRegisterType<CPlayerTank>("CustomTypes", 1, 0, "CPlayerTank");

    qRegisterMetaType<EDirection>("EDirection");
    qmlRegisterUncreatableType<MyEnum>("MyEnums", 1, 0, "EDirection", QStringLiteral("Cannot create objects of type MyEnum"));


    QQmlApplicationEngine engine;
    CControllerManager controllerManager;
    controllerManager.initializeAll(&engine);
    engine.load(QUrl(QStringLiteral("qrc:src/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    auto ret = app.exec();

    delete g_logger;
    g_logger = nullptr;

    return ret;
}
