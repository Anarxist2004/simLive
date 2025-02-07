#pragma once
#include "baseTools.h"

class Entity: public QGraphicsItem {
private:
	
	//BaseTools::Point2d point = null;
public:
	virtual void getPosition(float& x, float y) const=0 ;
	virtual BaseTools::Point2d position() const=0;
	virtual void setColor(QColor color) = 0;
	//virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
	//	// Базовая отрисовка, если нужно
	//	painter->setPen(Qt::black);
	//	painter->drawRect(boundingRect());  // Стандартная рамка
	//}
	//virtual QRectF boundingRect() const override;
	// {
	//	 QRectF a= QRectF();  // Размер по умолчанию
	//	 a.setCoords(point.x, point.y, 10,10);
	//	 return a;
	//}
};