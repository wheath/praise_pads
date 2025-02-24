#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "audiocontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    
    AudioController audioController;
    engine.rootContext()->setContextProperty("audioController", &audioController);

    const QUrl url(u"qrc:/main.qml"_qs);
    engine.load(url);

    return app.exec();
} 