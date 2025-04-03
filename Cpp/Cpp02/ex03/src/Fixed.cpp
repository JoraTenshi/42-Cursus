/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcallejo <jcallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:56:46 by jcallejo          #+#    #+#             */
/*   Updated: 2025/04/03 14:53:00 by jcallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(value * (1<< _fracBit));
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPoint = value << _fracBit;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &fixed)
		_fixedPoint = fixed.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

int	Fixed::toInt() const
{
	return (_fixedPoint >> _fracBit);
}

float Fixed::toFloat() const
{
	return ((float) _fixedPoint / (float) (1 << _fracBit));
}

std::ostream& operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return (Fixed(toFloat() / fixed.toFloat()));
}

Fixed & Fixed::operator++()
{
	_fixedPoint++;
	return (*this);
}

Fixed & Fixed::operator--()
{
	_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

bool Fixed::operator > (const Fixed &fixed)
{
	return (_fixedPoint > fixed.getRawBits());
}

bool Fixed::operator < (const Fixed &fixed)
{
	return (_fixedPoint < fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed &fixed)
{
	return (_fixedPoint >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed &fixed)
{
	return (_fixedPoint <= fixed.getRawBits());
}

bool Fixed::operator == (const Fixed &fixed)
{
	return (_fixedPoint == fixed.getRawBits());
}

bool Fixed::operator != (const Fixed &fixed)
{
	return (_fixedPoint != fixed.getRawBits());
}

Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed & Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed & Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

