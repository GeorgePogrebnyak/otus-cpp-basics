#include "World.h"
#include "Painter.h"
#include "Ball.h"
#include <fstream>

// ������������ ������ ���� ���������.
// ��������� ��. update()
// �������� �� �������
static constexpr double timePerTick = 0.001;

/**
 * ������������ ������ ���� ��� ���������
 * @param worldFilePath ���� � ����� ������ ����
 */
World::World(const std::string& worldFilePath) {

	std::ifstream stream(worldFilePath);
	/**
	 * TODO: ������� ����� ��� ���������.
	 * ������ ������ ���� �� ������
	 * �������� ��������, ��� ����� � ����� �� �����������
	 * ������ � ������ ���� Point, ���������������
	 * �������� ���������� x � �. ���� ���-�� ������
	 * ����������� - ������ �� ������� ��� � �������
	 * � �� ����������� ���...
	 */
	stream >> topLeft.x >> topLeft.y >> bottomRight.x >> bottomRight.y;
	physics.setWorldBox(topLeft, bottomRight);

	/**
	 * TODO: ������� ����� ��� ���������.
	 * (x, y) � (vx, vy) - ��������� ����� �������, �����
	 * ��� � (red, green, blue). ����� ��, ����� ���������
	 * ���� ���, ���������� ������ ����� Point, Color...
	 */
	double x;
	double y;
	double vx;
	double vy;
	double radius;

	double red;
	double green;
	double blue;

	bool isCollidable;

	// ����� �� ������� ��������� ������, �� �� �������
	// ������ ����������� ����� ��� ��� ����������
	while (stream.peek(), stream.good()) {
		// ������ ���������� ������ ���� (x, y) � ������
		// ��� �������� (vx, vy)
		stream >> x >> y >> vx >> vy;
		// ������ ��� ������������ ����� ����
		stream >> red >> green >> blue;
		// ������ ������ ����
		stream >> radius;
		// ������ �������� ���� isCollidable, �������
		// ���������, ��������� �� ������������ �����������
		// ����� ��� ������������. ���� true - ���������.
		// � ������� ����� ������� ���� ��������
		stream >> std::boolalpha >> isCollidable;

		Point position = { x, y };
		Velocity velocity = Point{ vx, vy };
		Color color = { red, green, blue };
		Ball ball(radius, position, velocity, color);
		balls.push_back(ball);
	}
}

/// @brief ���������� ��������� ����
void World::show(Painter& painter) const {
	// ������ ����� �������������, ������������ �������
	// ����
	painter.draw(topLeft, bottomRight, Color(1, 1, 1));

	// �������� ��������� ������� ����
	for (const Ball& ball : balls) {
		ball.draw(painter);
	}
}

/// @brief ��������� ��������� ����
void World::update(double time) {
	/**
	 * � �������� ���� ����� ����� ����������. ������
	 * ���������� ��������� �� ����� �������. �������
	 * ��������� �������������� ����� ��������� �����������
	 * "������". �.�. ���� � ������� ������� ���������
	 * ������ time ������, time / timePerTick ��� ���������
	 * ��������� ����. ������ ����� ���������� - ��� -
	 * � physics.update() ���������� ���� � ������������
	 * �������� - ��������, ����� � ���������� �����������
	 * ���� ��� ������������ � ������ ��� � �������� ����.
	 * � ����� ������ ����� �� ������� ������ ��
	 * ������������ ����, ��������� ������� � restTime
	 * � ������������ �� ��������� ��������.
	 */

	 // ��������� ������� �������, ������� �� �� "����������" ��� ������� update
	time += restTime;
	const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
	restTime = time - double(ticks) * timePerTick;

	physics.update(balls, ticks);
}
Ball::Ball(double radius, Point position, Velocity velocity, Color color) {
	this->radius = radius;
	this->center = position;
	this->velocity = velocity;

	mass = M_PI * pow(radius, 3.0) * 4 / 3;
}