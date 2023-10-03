#include "Ball.h"
#include <cmath>

/**
 * ������ �������� �������
 * @param velocity ����� �������� ��������
 */
void Ball::setVelocity(const Velocity& velocity) {
	this->velocity = velocity;
}

/**
 * @return �������� �������
 */
Velocity Ball::getVelocity() const {
	return velocity;
}

/**
 * @brief ��������� ��������� �������
 * @details ������ Ball ������������� �� �����������
 * ������� ����������� �������� �� ������. �� "������"
 * ���� � �����������, ������� ������������� Painter
 * ��������� ����������� ����� ������ painter.draw(...)
 * @param painter �������� ���������
 */
void Ball::draw(Painter& painter) const {
	this->color;
}

/**
 * ������ ���������� ������ �������
 * @param center ����� ����� �������
 */
void Ball::setCenter(const Point& center) {
	this->center = center;
}

/**
 * @return ����� �������
 */
Point Ball::getCenter() const {
	return center;
}

/**
 * @brief ���������� ������ �������
 * @details �������� ��������, ��� ����� setRadius()
 * �� ���������
 */
double Ball::getRadius() const {
	return radius;
}

/**
 * @brief ���������� ����� �������
 * @details � ����� ���������� �������, ��� ��� ����
 * ������� �� ����������� ��������� � �������������
 * ����������. � ���� ������ ����� � �������� ��������
 * ������������ ������: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
	return mass;
}
