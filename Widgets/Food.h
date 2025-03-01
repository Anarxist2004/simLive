#pragma once

#include "Entity.h"



class Food :public Entity {
public:
	Food();

	virtual void getPosition(float& x, float& y) const override;
	virtual Point2d position() const override;
	virtual void setColor(QColor color) override;
	virtual double getEnergy() override;

private:
	Point2d currentPosition;
	double d_energy;
	QColor m_color= Qt::green;
	QRectF boundingRect_;

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
	virtual QRectF boundingRect() const override;
	virtual bool setPosition(Point2d& p);
};