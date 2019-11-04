// Justin Ventura COSC220-003
// LAB4: complexx.h

#ifndef COMPLEXX_H
#define COMPLEXX_H

#include <iostream>

class complexx
{
private:
    double real; //real part
    double imag; //complexx part

public:
    complexx(double x=0.0, double y=0.0); //constructor

    complexx(const complexx& c); // copy constructor

    // return the real part of the complexx number
    double realPart() const
    { return real; }

    // return the imaginary part of the complexx number
    double imagPart() const
    { return imag; }

    // assignment operator overload
    complexx operator= (const complexx& rhs);

    // addition of complexx numbers
    complexx operator+ (const complexx& rhs);

    // division of complexx numbers
    complexx operator/ (const complexx& rhs);

    // negation of a complexx number
    complexx operator- () const;

    // subtraction of complexx numbers
    friend complexx operator- (const complexx& lhs, const complexx& rhs);

    // comparison of complexx numbers
    friend bool operator== (const complexx& lhs, const complexx& rhs);

    // stream input in format (real,imag)
    friend std::istream& operator>> (std::istream& istr,complexx& x);

    // multiplication of complexx numbers
    friend complexx operator* (const complexx& lhs, const complexx& rhs);

    // stream output in format (real,imag)
    friend std::ostream& operator<< (std::ostream& ostr, const complexx& x);

};

#endif
