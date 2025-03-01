#pragma once

#include <QtWidgets>
#include <QObject>
struct Point2d {
	float x, y;
	Point2d() : x(0.0f), y(0.0f) {}
	Point2d(float x_val, float y_val) : x(x_val), y(y_val) {}

	// Функция для вычисления расстояния до другой точки
	float distanceTo(const Point2d& other) const {
		float dx = x - other.x;
		float dy = y - other.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	float len() const {
		return std::sqrt(x * x + y * y);
	}

	void normalize() {
		float len = this->len();
		if (len > 0.0f) { // Чтобы избежать деления на 0
			x /= len;
			y /= len;
		}
	}

	//операторы
	Point2d operator+(const Point2d& other) const {
		return Point2d(x + other.x, y + other.y);
	}

	Point2d operator-(const Point2d& other) const {
		return Point2d(x - other.x, y - other.y);
	}

	Point2d operator*(const float scalar) {
		return Point2d(scalar * x, scalar * y);
	}
};

class Entity: public QGraphicsObject {
	//Q_OBJECT
private:
	
	//BaseTools::Point2d currentPosition = null;
public:
	virtual void getPosition(float& x, float& y) const=0 ;
	virtual Point2d position() const=0;
	virtual void setColor(QColor color) = 0;
	virtual bool setPosition(Point2d& p) = 0;
	virtual double getEnergy() = 0;
	//virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
	//	// Базовая отрисовка, если нужно
	//	painter->setPen(Qt::black);
	//	painter->drawRect(boundingRect());  // Стандартная рамка
	//}
	//virtual QRectF boundingRect() const override;
	// {
	//	 QRectF a= QRectF();  // Размер по умолчанию
	//	 a.setCoords(currentPosition.x, currentPosition.y, 10,10);
	//	 return a;
	//}
};