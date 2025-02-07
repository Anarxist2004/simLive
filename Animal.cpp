#include "stdafx.h"
#include "Animal.h"

Animal::Animal()
{
	point.x = 0;
	point.y = 0;
	energy = 100;
}

void Animal::getPosition(float& x, float y) const
{
	x = point.x;
	y = point.y;
}

BaseTools::Point2d Animal::position() const
{
	return point;
}

void Animal::setColor(QColor color)
{
	m_color = color;
	update();  
}

void Animal::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

	painter->setPen(Qt::black);
	painter->setBrush(Qt::red);

	painter->drawEllipse(boundingRect());  
}

QRectF Animal::boundingRect() const
{
	QRectF a = QRectF();
	a.setCoords(point.x - 5, point.y - 5, point.x + 5, point.y + 5);  // Окружность с радиусом 5
	return a;
}
