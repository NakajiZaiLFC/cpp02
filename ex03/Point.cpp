#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other)
{
	return *this;
}

Point::~Point() {}

Point::Point(const float val_x, const float val_y) : x(val_x), y(val_y) {}

Fixed Point::getX(void) const
{
	return this->x;
}

Fixed Point::getY(void) const
{
	return this->y;
}