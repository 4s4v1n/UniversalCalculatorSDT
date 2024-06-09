#include <QGuiApplication>
#include <QCoreApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQuick/QQuickView>

#include "controller/complex_number_controller.hpp"
#include "controller/fraction_number_controller.hpp"
#include "controller/p_number_controller.hpp"

#include "model/number/complex_number.hpp"
#include "model/number/fraction_number.hpp"
#include "model/number/p_number.hpp"

auto main(int argc, char *argv[]) -> int
{
    QGuiApplication       app    {argc, argv};
    QQmlApplicationEngine engine {};

    QGuiApplication::setOrganizationName("NSTU");
    QGuiApplication::setApplicationName("UniversalCalculator");

    ComplexNumberController  complexNumberController;
    FractionNumberController fractionNumberController;
    PNumberController        pNumberController;

    auto ctx = engine.rootContext();

    ctx->setContextProperty("complexNumberController",  &complexNumberController);
    ctx->setContextProperty("fractionNumberController", &fractionNumberController);
    ctx->setContextProperty("pNumberController",        &pNumberController);

    const QUrl url{u"qrc:Converter/view/main.qml"_qs};
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); },
                     Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
