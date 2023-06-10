#include "iconwidget.h"
#include <QPainter>

IconWidget::IconWidget(QWidget *parent)
    : QWidget{parent}
{

}


void IconWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // Set up the colors and pen
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);

    // Draw the head
    painter.drawEllipse(QRectF(50, 50, 200, 200));

    // Set up the colors for the ears
    painter.setBrush(Qt::black);

    // Draw the left ear
    painter.drawPie(QRectF(30, 30, 100, 100), 0, 180 * 16);

    // Draw the right ear
    painter.drawPie(QRectF(170, 30, 100, 100), 0, 180 * 16);

    // Set up the colors for the face
    painter.setBrush(Qt::white);

    // Draw the face
    painter.drawEllipse(QRectF(70, 70, 120, 120));

    // Set up the colors for the eyes and nose
    painter.setBrush(Qt::black);

    // Draw the left eye
    painter.drawEllipse(QRectF(90, 110, 20, 20));

    // Draw the right eye
    painter.drawEllipse(QRectF(150, 110, 20, 20));

    // Draw the nose
    painter.drawEllipse(QRectF(120, 150, 20, 20));
}
