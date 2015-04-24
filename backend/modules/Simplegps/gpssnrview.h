#ifndef GPSSNRVIEW_H
#define GPSSNRVIEW_H

#include <QQuickPaintedItem>

#include "gpsdataprovider.h"


class GPSSNRView : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(GPSDataProvider* gpsDataProvider WRITE setGPSDataProvider)


public:
    GPSSNRView(QQuickItem *parent = 0);
    ~GPSSNRView();

    void paint(QPainter *painter);

    void setGPSDataProvider(GPSDataProvider* provider);


private:
    GPSDataProvider* m_gpsDataProvider;
};

#endif // GPSSNRVIEW_H

