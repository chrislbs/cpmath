#ifndef _cp_frac_h_
#define _cp_frac_h_

namespace cp { namespace math {

class fraction
{
	int numerator;
	int denominator;
public:
	fraction();
	fraction(int num, int den);

	inline int get_denominator() const { return denominator; }
	inline int get_numerator() const { return numerator; }

	fraction operator*(const fraction& rhs);
	fraction& operator*=(const fraction& rhs);

	fraction operator/(const fraction& rhs);
	fraction& operator/=(const fraction& rhs);

	fraction operator+(const fraction& rhs);
	fraction& operator+=(const fraction& rhs);

	fraction operator-(const fraction& rhs);
	fraction& operator-=(const fraction& rhs);

	void simplify();
};

int get_lcd(const fraction& f1, const fraction& f2);

fraction simplify(const fraction& f);

} }

#endif
