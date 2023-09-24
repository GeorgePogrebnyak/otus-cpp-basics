#pragma once
#include "Painter.h"
#include "Point.h"
#include "Velocity.h"

class Ball {
public:
	void setVelocity(const Velocity& velocity);
	Velocity getVelocity() const;
	void draw(Painter& painter) const;
	void setCenter(const Point& center);
	Point getCenter() const;
	double getRadius() const;
	double getMass() const;
	const double Pi = 3.14;
	double Mass = Pi * pow(Radius, 3.0) * 4 / 3;
private:
	Velocity velocity;
	Point center;
	double Radius = 5;
};
