#include <QDebug>

#include "gpsdataprovider.h"


GPSDataProvider::GPSDataProvider(QObject *parent) :
    QObject(parent)
{
    QGeoSatelliteInfoSource* source = QGeoSatelliteInfoSource::createDefaultSource(this);

    // Check if source is valid
    if(source)
    {
        qDebug() << "Source valid";
        connect(source, SIGNAL(satellitesInViewUpdated(QList<QGeoSatelliteInfo>)),
                this, SLOT(satellitesInViewUpdated(QList<QGeoSatelliteInfo>)));
        source->startUpdates();

        m_source = source;
    }
    else
    {
        qDebug() << "Source invalid";

        m_source = NULL;
    }
}


GPSDataProvider::~GPSDataProvider() {

}


bool GPSDataProvider::enabled()
{
    return false;
}


int GPSDataProvider::interval()
{
    return m_interval;
}


int GPSDataProvider::satelliteCount()
{
    return 0;
}


void GPSDataProvider::setInterval(int interval)
{
    if(interval > 0)
        m_interval = interval;
}


void GPSDataProvider::satellitesInViewUpdated(const QList<QGeoSatelliteInfo> & satellites)
{
    qDebug() << "satellites in view updated";
}
