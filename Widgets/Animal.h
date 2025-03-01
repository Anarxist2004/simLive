#pragma once

#include "Entity.h"


	class Animal : public Entity {
	
	public:
		Animal();
		Animal(float scope, float m_arm, float spead);
		Animal(const Animal& other);//копирование

		~Animal();
		virtual void getPosition(float& x, float& y) const override;
		virtual Point2d position() const override;
		virtual void setColor(QColor color) override;
		virtual double getEnergy() override;
		void setEnergy(double en);
		int scope();
		int age();
		void setScope(int scope);
		void setRect(Point2d leftDown, Point2d rightUp);
		
		void chooseTarget(std::vector <Entity*>& entArr, std::vector<Entity*>& entEatenArr);
		void modifyAttribute(float chance, int n_percent);
		void moveRandomly();
		QColor generateColor();
		QRectF m_body;
	private:
		Point2d currentPosition;
		bool haveGoal = false;
		Point2d targetPosition;
		float d_energy;
		float m_scope;//обзор
		float m_arm;//рука
		int m_age=0;
		float m_speed;
		
		QColor m_color= Qt::transparent;

	


		Point2d leftDown, rightUp;//края так не должно быть

		virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
		virtual QRectF boundingRect() const override;
		virtual bool setPosition(Point2d& p) override;
		void spendEnergy();
		double calculateEnergyConsumption();
	};