#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : m_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &param) : m_value(param << FRAC_BITS)
{
	std::cout << "Int contructor called" << std::endl;
}

Fixed::Fixed(const float &param) : m_value(roundf(param * (1 << FRAC_BITS)))
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
	return static_cast<float>(this->m_value) / (1 << FRAC_BITS);
}

int Fixed::toInt(void) const
{
	return m_value >> FRAC_BITS;
}