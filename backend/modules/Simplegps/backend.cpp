#include <QtQml>
#include <QtQml/QQmlContext>

#include "backend.h"

#include "gpsdataprovider.h"
#include "gpslocationview.h"
#include "gpssnrview.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Simplegps"));

    qmlRegisterType<GPSDataProvider>(uri, 1, 0, "GPSDataProvider");
    qmlRegisterType<GPSLocationView>(uri, 1, 0, "GPSLocationView");
    qmlRegisterType<GPSSNRView>(uri, 1, 0, "GPSSNRView");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

