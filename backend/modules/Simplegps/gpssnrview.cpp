#include <QBrush>
#include <QPainter>

#include "gpssnrview.h"


GPSSNRView::GPSSNRView(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{

}


GPSSNRView::~GPSSNRView() {

}


void GPSSNRView::paint(QPainter *painter)
{
    QBrush brush(QColor("red"));

    painter->setBrush(brush);

    painter->drawRect(0, 0, width(), height());
}


void GPSSNRView::setGPSDataProvider(GPSDataProvider* provider)
{
    m_gpsDataProvider = provider;
}
