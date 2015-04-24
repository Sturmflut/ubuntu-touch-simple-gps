#include <QBrush>
#include <QPainter>

#include "gpslocationview.h"


GPSLocationView::GPSLocationView(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_gpsDataProvider(NULL)
{

}


GPSLocationView::~GPSLocationView() {

}


void GPSLocationView::paint(QPainter *painter)
{
    QBrush brush(QColor("green"));

    painter->setBrush(brush);

    painter->drawRect(0, 0, width(), height());
}


void GPSLocationView::setGPSDataProvider(GPSDataProvider* provider)
{
    m_gpsDataProvider = provider;
}
