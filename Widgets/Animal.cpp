#include "Animal.h"
#include "Animal.h"
#include <QtCore>
#include <QTimer>
#include <QGraphicsItem>
#include <iostream>
#include <algorithm>  // ��� std::min � std::max

Animal::Animal()
{
	currentPosition.x = 0;
	currentPosition.y = 0;
	d_energy = 200;
	m_body = QRectF(QPointF(0, 0), QSizeF(4, 4)).translated(-2, -2);
}

Animal::Animal(float scope, float m_arm, float m_spead):m_scope(scope),  m_arm( m_arm), m_speed(m_spead)
{
	currentPosition.x = 0;
	currentPosition.y = 0;
	d_energy =290;
	m_body = QRectF(QPointF(0,0), QSizeF(4, 4)).translated(-2, -2);
	//m_scopeRect = QRectF(QPointF(0, 0), QSizeF(scope, scope)).translated(-scope * 0.5, -scope * 0.5);
	//m_body = QRectF(currentPosition.x - 5, currentPosition.y - 5, 10, 10);
	//m_scopeRect = QRectF(currentPosition.x - scope/2, currentPosition.y - scope / 2, scope , scope );
}

Animal::Animal(const Animal& other)
	: currentPosition(other.currentPosition),
	d_energy(other.d_energy),
	m_scope(other.m_scope),
	m_color(other.m_color),
	leftDown(other.leftDown),
	rightUp(other.rightUp),
	m_body(other.m_body),
	m_arm(other.m_arm),
	m_speed(other.m_speed)
{

}

Animal::~Animal()
{

}

void Animal::getPosition(float& x, float& y) const
{
	x = currentPosition.x;
	y = currentPosition.y;
}

Point2d Animal::position() const
{
	return currentPosition;
}

void Animal::setColor(QColor color)
{
	m_color = color;
	update();  
}

double Animal::getEnergy()
{
	return d_energy;
}

void Animal::setEnergy(double en)
{
	d_energy = en;
}

int Animal::scope()
{
	return m_scope;
}

int Animal::age()
{
	return m_age;
}

void Animal::setScope(int scope)
{
	m_scope = scope;
	//m_scopeRect = QRectF(currentPosition.x - scope / 2, currentPosition.y - scope / 2, scope, scope);
}

void Animal::setRect(Point2d leftD, Point2d rightU)
{
	leftDown = leftD;
	rightUp = rightU;
}

void Animal::chooseTarget(std::vector<Entity*>& entArr, std::vector<Entity*>& entEatenArr )
{
	bool findNewGoal = false;
	Entity* closestEntity = nullptr;
	double minDist = std::numeric_limits<double>::max();

	auto it = entArr.begin();
	while (it != entArr.end()) {
		Entity* ent = *it;
		double dist = (ent->position() - currentPosition).len();

		if (dist <= m_arm) {
			// ������ ��������
			d_energy += ent->getEnergy();
			entEatenArr.push_back(ent);
			it = entArr.erase(it); // ������� �� ��������� �������
			haveGoal = false; // ����� ����, ���� �����
		}
		else {
			// ���� ��������� ����
			if (!haveGoal || dist < minDist) {
				closestEntity = ent;
				minDist = dist;
				findNewGoal = true;
			}
			++it;
		}
	}

	if (findNewGoal) {
		targetPosition = closestEntity->position();
		haveGoal = true;
	}
}

void Animal::modifyAttribute(float chance, int n_percent)
{
	// ��������� ��������� �����
	static std::default_random_engine generator(static_cast<unsigned long>(time(0)));
	std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

	// �������� �� ���������� ��������� � ������
	if (distribution(generator) <= chance) {
		// ��������� ����� ����� �� ����������
		int random_attribute = rand() % 3;  // 0 - m_speed, 1 - m_arm, 2 - m_scope
		int percent_change = (rand() % (n_percent + 1)); // ��������� �������� �� 0 �� n%

		// ����������� ����������� ��������� (-1 ��� 1)
		int direction = (rand() % 2 == 0) ? -1 : 1;

		switch (random_attribute) {
		case 0:
			m_speed += m_speed * percent_change * direction / 100;
			break;
		case 1:
			m_arm += m_arm * percent_change * direction / 100;
			break;
		case 2:
			m_scope += m_scope * percent_change * direction / 100;
			break;
		}
	}
}


void Animal::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{

	painter->setPen(m_color);
	painter->setBrush(m_color);

	painter->drawEllipse(m_body);

//	painter->setPen(Qt::black);
//	painter->setBrush(Qt::transparent);

//	painter->drawEllipse(m_scopeRect);
}

QRectF Animal::boundingRect() const
{
	return m_body;
}

bool Animal::setPosition(Point2d& p)
{
	currentPosition = p;
	return true;
}

void Animal::spendEnergy()
{
	//
	d_energy -= calculateEnergyConsumption();
}

double Animal::calculateEnergyConsumption()
{
	// ������������ ������� ���������� �� ������ �������
	const double speedFactor = 0.3;  // ������ ������� ����� (��������, ������� �������� ������ �����)
	const double armFactor = 0.2;    // ������ �������� (����������� ���� ������� �������)
	const double scopeFactor = 0.125;  // ������ ���������� (������� �� ���������)

	// ������� ����������������� + ����� ���������� ����������
	double baseEnergy = 0.0;  // ����������� ����������� �������
	double energyCost = baseEnergy +
		(m_speed * speedFactor) +
		(m_arm * armFactor) +
		(m_scope * scopeFactor);

	return energyCost;
}


void Animal::moveRandomly(){

	spendEnergy();
	if (d_energy <= 0||m_age>=300)
		return;

	m_age++;

	double angle = (rand() % 360) * M_PI / 180.0; // ��������� ���� �� 0 �� 2PI
	int stepSize = m_speed;
	// ��������� ������� �����
	//currentPosition.x=(currentPosition.x + stepSize * std::cos(angle));
	//currentPosition.y=(currentPosition.y + stepSize * std::sin(angle));
	if (!haveGoal) {
		Point2d newPoint = Point2d(currentPosition.x + stepSize * std::cos(angle), currentPosition.y + stepSize * std::sin(angle));

		if (newPoint.x < leftDown.x) newPoint.x = leftDown.x;
		if (newPoint.x > rightUp.x) newPoint.x = rightUp.x;
		if (newPoint.y < leftDown.y) newPoint.y = leftDown.y;
		if (newPoint.y > rightUp.y) newPoint.y = rightUp.y;

		//setPos(vecMove.x, vecMove.y);
		QPropertyAnimation* animation = new QPropertyAnimation(this, "pos", this);
		animation->setDuration(100);
		animation->setStartValue(QPointF(currentPosition.x, currentPosition.y));
		animation->setEndValue(QPointF(newPoint.x, newPoint.y));
		//animation->setEasingCurve(QEasingCurve::OutBounce);
		animation->start();
		currentPosition = newPoint;
	}
	else {
		Point2d vecMove = (targetPosition - currentPosition);
		vecMove.normalize();
		vecMove = vecMove*stepSize;
		Point2d newPoint = Point2d(currentPosition.x + vecMove.x, currentPosition.y + vecMove.y);;
		QPropertyAnimation* animation = new QPropertyAnimation(this, "pos", this);
		animation->setDuration(100);
		animation->setStartValue(QPointF(currentPosition.x, currentPosition.y));
		animation->setEndValue(QPointF(newPoint.x, newPoint.y));
		//animation->setEasingCurve(QEasingCurve::OutBounce);
		animation->start();
		currentPosition = newPoint;
	}

	//m_body = QRectF(currentPosition.x - 5, currentPosition.y - 5, 10, 10);
	//m_scopeRect = QRectF(currentPosition.x - m_scope / 2, currentPosition.y - m_scope / 2, m_scope, m_scope);
	
	
}

QColor Animal::generateColor()
{
	int sum = m_speed + m_arm + m_scope;
	int count = 3;
	int avg_value = sum / count;

	// ����������� ��������� ������������ �������� �������� (� �������� �� 0 �� 1)
	double red_normalized = (avg_value == 0) ? 0.0 : static_cast<double>(m_speed) / avg_value;
	double green_normalized = (avg_value == 0) ? 0.0 : static_cast<double>(m_arm) / avg_value;
	double blue_normalized = (avg_value == 0) ? 0.0 : static_cast<double>(m_scope) / avg_value;

	// �������� �� 255 � ���������, ����� �� �������� �� �������
	int red = std::min(static_cast<int>(red_normalized * 255), 255);
	int green = std::min(static_cast<int>(green_normalized * 255), 255);
	int blue = std::min(static_cast<int>(blue_normalized * 255), 255);

	// ���������� QColor � ���������������� ������������
	return QColor(red, green, blue);
}
