#include "cpfrac.h"
#include "cpprime.h"
#include <stdexcept>

namespace cp { namespace math {

fraction::fraction()
	:numerator(1), denominator(1)
{
}

fraction::fraction(int n, int d)
	:numerator(n), denominator(d)
{
	if(d == 0)
		throw std::invalid_argument("denominator cannot be 0");
}

fraction fraction::operator*(const fraction& rhs)
{
	return fraction(
		numerator * rhs.numerator,
		denominator * rhs.denominator);
}

fraction& fraction::operator*=(const fraction& rhs)
{
	numerator *= rhs.numerator;
	denominator *= rhs.denominator;
	return *this;
}

fraction fraction::operator/(const fraction& rhs)
{
	return fraction(
		numerator * rhs.denominator,
		denominator * rhs.numerator);
}

fraction& fraction::operator/=(const fraction& rhs)
{
	numerator *= rhs.denominator;
	denominator *= rhs.numerator;
	return *this;
}

fraction fraction::operator+(const fraction& rhs)
{
	int lcd = get_lcd(*this, rhs);
	return fraction(
		numerator * (lcd / denominator) +
		rhs.numerator * (lcd / rhs.denominator),
		lcd);
}

fraction& fraction::operator+=(const fraction& rhs)
{
	int lcd = get_lcd(*this, rhs);
	numerator = numerator * (lcd / denominator) +
		rhs.numerator * (lcd / rhs.denominator);
	denominator = lcd;

	return *this;
}

fraction fraction::operator-(const fraction& rhs)
{
	int lcd = get_lcd(*this, rhs);
	return fraction(
		numerator * (lcd / denominator) -
		rhs.numerator * (lcd / rhs.denominator),
		lcd);
}

fraction& fraction::operator-=(const fraction& rhs)
{
	int lcd = get_lcd(*this, rhs);
	numerator = numerator * (lcd / denominator) -
		rhs.numerator * (lcd / rhs.denominator);
	denominator = lcd;

	return *this;
}

void fraction::simplify()
{
	int gcf = get_gcf(numerator, denominator);
	numerator /= gcf;
	denominator /= gcf;
}

int get_lcd(const fraction& f1, const fraction& f2)
{
	return (f1.get_denominator() * f2.get_denominator()) /
		get_gcf(f1.get_denominator(), f2.get_denominator());
}

fraction simplify(const fraction& f)
{
	int gcf = get_gcf(f.get_numerator(), f.get_denominator());
	return fraction(
		f.get_numerator() / gcf, f.get_denominator() / gcf);
}

} }
