#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	m_value = 0;
}

Fixed::Fixed(const int &param) : m_value(param << FRAC_BITS)
{
}

Fixed::Fixed(const float &param) : m_value(roundf(param * (1 << FRAC_BITS)))
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->m_value = other.m_value;
	}
	return *this;
}

Fixed::~Fixed()
{
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
	return out << f.toFloat();
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->m_value > rhs.m_value;
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->m_value < rhs.m_value;
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->m_value >= rhs.m_value;
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->m_value <= rhs.m_value;
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->m_value == rhs.m_value;
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->m_value != rhs.m_value;
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits(this->m_value + rhs.m_value);
	return result;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits(this->m_value - rhs.m_value);
	return result;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed result;
	long temp_val = static_cast<long>(this->m_value) * static_cast<long>(rhs.m_value);

	result.setRawBits(temp_val >> FRAC_BITS);
	return result;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed result;
	long temp_val = static_cast<long>(this->m_value) << FRAC_BITS;

	result.setRawBits(temp_val / rhs.m_value);
	return result;
}

Fixed &Fixed::operator++()
{
	this->m_value++;
	return *this;
}

Fixed &Fixed::operator--()
{
	this->m_value--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed result;
	result.setRawBits(this->m_value);
	this->m_value++;
	return result;
}

Fixed Fixed::operator--(int)
{
	Fixed result;
	result.setRawBits(this->m_value);
	this->m_value--;
	return result;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

int Fixed::getRawBits(void) const
{
	return m_value;
}

void Fixed::setRawBits(int const raw)
{
	m_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(m_value) / (1 << FRAC_BITS);
}

int Fixed::toInt(void) const
{
	return m_value >> FRAC_BITS;
}