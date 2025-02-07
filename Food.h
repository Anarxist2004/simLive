#pragma once
#include "BaseTools.h"
#include "Entity.h"




class Food :public Entity {
public:
	Food();

	virtual void getPosition(float& x, float y) const override;
	virtual BaseTools::Point2d position() const override;
	virtual void setColor(QColor color) override;
private:
	BaseTools::Point2d point;
	int energy;
	QColor m_color= Qt::yellow;
	QRectF boundingRect_;

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	virtual QRectF boundingRect() const override;
	
};