#include "stdafx.h"
#include "Food.h"

Food::Food()
{
	point = BaseTools::Point2d(BaseTools::generateRandomFloat(), BaseTools::generateRandomFloat());
	energy = BaseTools::generateRandomInt();
	boundingRect_ = QRectF(point.x - 5, point.y - 5, 10, 10);
}

void Food::getPosition(float& x, float y) const
{
	x = point.x;
	y = point.y;
}

BaseTools::Point2d Food::position() const
{
	return point;
}

void Food::setColor(QColor color)
{
	m_color = color;
	update();  // Перерисовываем элемент

}

void Food::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

	painter->setPen(m_color);
	painter->setBrush(m_color);  // Устанавливаем цвет заливки (опционально)

	painter->drawEllipse(boundingRect_);  // Отрисовываем окружность вместо прямоугольника
}

QRectF Food::boundingRect() const
{
	
	return boundingRect_;
}
