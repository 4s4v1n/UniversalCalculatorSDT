#include <QGuiApplication>
#include <QCoreApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "controller/controller.hpp"

auto main(int argc, char *argv[]) -> int
{
    QGuiApplication       app    {argc, argv};
    QQmlApplicationEngine engine {};

    QGuiApplication::setOrganizationName("NSTU");
    QGuiApplication::setApplicationName("Calculator");

    engine.rootContext()->setContextProperty("Controller",   Controller::getInstance());

    const QUrl url{u"qrc:Converter/view/main.qml"_qs};
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
