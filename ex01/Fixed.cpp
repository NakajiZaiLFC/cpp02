#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	m_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &param) : m_value(param << m_num)
{
	std::cout << "Int contructor called" << std::endl;
}

Fixed::Fixed(const float &param) : m_value(std::roundf(param *(1 << 8)))
{
	std::cout << "Float contructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->m_value = other.m_value;
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	return out << f.toFloat();
}

float Fixed::toFloat(void) const
{
	return (float)m_value / (1 << m_num);
}

int Fixed::toInt(void) const
{
	return m_value >> m_num;
}