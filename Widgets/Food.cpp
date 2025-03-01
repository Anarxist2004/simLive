
#include "Food.h"
#include "..\ATools\BaseTools.h"
Food::Food()
{
	currentPosition = Point2d(BaseTools::generateRandomFloat(), BaseTools::generateRandomFloat());
	d_energy = BaseTools::generateRandomInt();
	boundingRect_ = QRectF(currentPosition.x - 1, currentPosition.y - 1, 2, 2);
}

void Food::getPosition(float& x, float& y) const
{
	x = currentPosition.x;
	y = currentPosition.y;
}

Point2d Food::position() const
{
	return currentPosition;
}

void Food::setColor(QColor color)
{
	m_color = color;
	update();  // Перерисовываем элемент

}

double Food::getEnergy()
{
	return d_energy;
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

bool Food::setPosition( Point2d& p)
{
	currentPosition = p;
	return true;
}
