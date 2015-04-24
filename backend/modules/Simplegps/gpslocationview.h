#ifndef GPSLOCATIONVIEW_H
#define GPSLOCATIONVIEW_H

#include <QQuickPaintedItem>

#include "gpsdataprovider.h"


class GPSLocationView : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(GPSDataProvider* gpsDataProvider WRITE setGPSDataProvider)


public:
    GPSLocationView(QQuickItem *parent = 0);
    ~GPSLocationView();

    void paint(QPainter *painter);

    void setGPSDataProvider(GPSDataProvider* provider);

private:
    GPSDataProvider* m_gpsDataProvider;
};

#endif // GPSLOCATIONVIEW_H

