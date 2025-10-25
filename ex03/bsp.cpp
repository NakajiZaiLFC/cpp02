#include "Point.hpp"

static bool allPositive(Fixed sign1,Fixed sign2,Fixed sign3)
{
	if ((sign1 > 0) && (sign2 > 0) && (sign3 > 0))
		return true;
	return false;
}

static bool allNegative(Fixed sign1,Fixed sign2,Fixed sign3)
{
	if ((sign1 < 0) && (sign2 < 0) && (sign3 < 0))
		return true;
	return false;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed sign1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed sign2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed sign3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	if (allPositive(sign1, sign2, sign3) || allNegative(sign1, sign2, sign3))
		return true;
	return false;
}