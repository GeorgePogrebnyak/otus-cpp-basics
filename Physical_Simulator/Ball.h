#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
public:
	Ball(double radius, Point position, Velocity velocity);
	void setVelocity(const Velocity& velocity);
	Velocity getVelocity() const;
	void draw(Painter& painter) const;
	void setCenter(const Point& center);
	Point getCenter() const;
	double getRadius() const;
	double getMass() const;
private:
	Velocity velocity;
	Point center;
	double radius = 5;
	double Mass = M_PI * pow(radius, 3.0) * 4 / 3;
};
