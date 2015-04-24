#ifndef GPSDATAPROVIDER_H
#define GPSDATAPROVIDER_H

#include <QObject>

#include <QtPositioning/QGeoSatelliteInfoSource>


class GPSDataProvider : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int interval READ interval WRITE setInterval)


public:
    GPSDataProvider(QObject *parent = 0);
    ~GPSDataProvider();

    bool enabled();
    int interval();

    int satelliteCount();

    void setInterval(int interval);


Q_SIGNALS:
    void updated();


private:
    QGeoSatelliteInfoSource* m_source;

    int m_interval;


private slots:
    void satellitesInViewUpdated(const QList<QGeoSatelliteInfo> & satellites);
};

#endif // GPSDATAPROVIDER_H

