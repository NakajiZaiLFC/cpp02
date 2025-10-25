#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	Fixed(const int &param);
	Fixed(const float &param);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int m_value;
	static const int m_num = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif
