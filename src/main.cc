
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include "process_environment_model/processenvironmentmodel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    const QProcessEnvironment &sysEnv { QProcessEnvironment::systemEnvironment() };
    ProcessEnvironmentModel envModel { sysEnv };
    engine.rootContext()->setContextProperty("environmentModel", &envModel);

    engine.load(url);

    return app.exec();
}
