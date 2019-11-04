// Justin Ventura COSC220-003
// LAB4: complexx.cpp

#include "complexx.h"
#include <iostream>
// constructor
complexx::complexx(double x, double y)
{
    real = x;
    imag = y;
}
// copy constructor
complexx::complexx(const complexx& c)
{
    real = c.realPart();
    imag = c.imagPart();
}
// assignment operator overload
complexx complexx::operator= (const complexx& rhs)
{
    real = rhs.realPart();
    imag = rhs.imagPart();
}
// addition of complexx numbers
complexx complexx::operator+ (const complexx& rhs)
{
    return complexx((real + rhs.realPart()), (imag + rhs.imagPart()));
}
// division of complexx numbers
complexx complexx::operator/ (const complexx& rhs)
{
    double a = real, b = imag, c = rhs.realPart(), d = rhs.imagPart();
    double temp_real = ((a*c) + (b*d))/((c*c) + (d*d));
    double temp_imag = ((b*c)-(a*d))/((c*c) + (d*d));
    return complexx(temp_real, temp_imag);
}
// negation of a complexx number
complexx complexx::operator- () const
{
    return complexx((-1)*real, (-1)*imag);
}
// subtraction of complexx numbers, friend
complexx operator- (const complexx& lhs, const complexx& rhs)
{
    return complexx((lhs.real - rhs.real), (lhs.imag - rhs.imag));
}
// comparison of complexx numbers, friend
bool operator== (const complexx& lhs, const complexx& rhs)
{
    if (lhs.real == rhs.real && lhs.imag == rhs.imag) return true;
    return false;
}
// stream input in format (real,imag)
std::istream& operator>> (std::istream& istr, complexx& x)
{
    istr >> x.real >> x.imag;
    return istr;
}
// multiplication of complexx numbers
complexx operator* (const complexx& lhs, const complexx& rhs)
{
    return complexx((lhs.realPart() * rhs.realPart()) - (lhs.imagPart() * rhs.imagPart()),
    ((lhs.realPart() * rhs.imagPart()) + (lhs.imagPart() * rhs.realPart())));
}
// stream output in format (real,imag), friend
std::ostream& operator<< (std::ostream& ostr, const complexx& x)
{
    ostr << "(" << x.real << ", " << x.imag << "i)";
    return ostr;
}
