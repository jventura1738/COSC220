/*
* shapeTryRecenter.h
* Definition (header) of the shapeTryRecenter helper functions
* Author: Justin Ventura
* Created: September 20, 2019
* Current: September 21, 2019
*/

#include "shapeTryRecenter.h"
#include <iostream>

bool canBeRecentered(Circle &C1)
{
    // this will be used to see whether the shape needs to be shifted
    bool willFit = C1.canFit();
    // early condition checks
    if (willFit == true) return true;
    if (C1.getRadius() > 5.0) return false;
    // setting reasonable values for the co-ordinates
    if (C1.c.getX() <= -10) C1.c.setX(-9);  // if X too far left, shift to right bound
    if (C1.c.getX() >= 10) C1.c.setX(9);    // if X too far right, shift to left bound
    if (C1.c.getY() <= -5) C1.c.setY(-4);   // if Y too far down, shift to lower bound
    if (C1.c.getY() >= 5) C1.c.setY(4);     // if Y too far up, shift to upper bound
    // another early check, since if radius is one it should fit now
    if (C1.getRadius() == 1) return true;
    /* this loop shifts X co-ordinate until the radius no longer
    surpasses the 20x10 grid bounds */
    while ((C1.c.getX() + C1.getRadius()) > 10 || (C1.c.getX() - C1.getRadius()) < -10)
    {
        // shifts X one to the left if the radius passes the right edge of grid
        if (C1.c.getX() > 0 && (C1.c.getX() + C1.getRadius()) > 10)
        {
            C1.c.setX(C1.c.getX() - 1);
            willFit = C1.canFit(); // checks if the shape fits after shift
        }
        // shifts X one to the right if the radius passes the left edge of grid
        else if (C1.c.getX() < 0 && (C1.c.getX() - C1.getRadius()) < -10)
        {
            C1.c.setX(C1.c.getX() + 1);
            willFit = C1.canFit(); // checks if the shape fits after shift
        }
        if (willFit == true) return true; // if shape fits after shift, return true
    } //end while loop for X
    /* this loop shifts Y co-ordinate until the radius no longer
    surpasses the 20x10 grid bounds */
    while ((C1.c.getY() + C1.getRadius()) > 5 || (C1.c.getY() - C1.getRadius()) < -5)
    {
        // shifts Y one down if the radius passes the top edge of grid
        if (C1.c.getY() > 0 && (C1.c.getY() + C1.getRadius()) > 5)
        {
            C1.c.setY(C1.c.getY() - 1);
            willFit = C1.canFit(); // checks if the shape fits after shift
        }
        // shifts Y one up if the radius passes the bottom edge of grid
        else if (C1.c.getY() < 0 && (C1.c.getY() - C1.getRadius()) < -5)
        {
            C1.c.setY(C1.c.getY() + 1);
            willFit = C1.canFit(); // checks if the shape fits after shift
        }
        if (willFit == true) return true; // if shape fits after shift, return true
    } //end while loop for X
    return false;
}
bool canBeRecentered(Square &S1)
{
    // this will be used to see whether the shape needs to be shifted
    bool willFit = S1.canFit();
    // early condition checks
    if (willFit == true) return true;
    if (S1.getSide()/2 > 5.0) return false;
    // setting reasonable values for the co-ordinates
    if (S1.c.getX() <= -10) S1.c.setX(-9);  // if X too far left, shift to right bound
    if (S1.c.getX() >= 10) S1.c.setX(9);    // if X too far right, shift to left bound
    if (S1.c.getY() <= -5) S1.c.setY(-4);   // if Y too far down, shift to lower bound
    if (S1.c.getY() >= 5) S1.c.setY(4);     // if Y too far up, shift to upper bound
    // another early check, since if side is one it should fit now
    if (S1.getSide()== 1) return true;
    /* this loop shifts X co-ordinate until the side no longer
    surpasses the 20x10 grid bounds */
    while ((S1.c.getX() + S1.getSide()/2.0 > 10) || (S1.c.getX() - S1.getSide()/2.0 < -10))
    {
        // shifts X one to the left if the side passes the right edge of grid
        if (S1.c.getX() > 0 && (S1.c.getX() + S1.getSide()/2.0) > 10)
        {
            S1.c.setX(S1.c.getX() - 1);
            willFit = S1.canFit(); // checks if the shape fits after the shift
        }
        // shifts X one to the rught if the side passes the left edge of grid
        else if (S1.c.getX() < 0 && (S1.c.getX() - S1.getSide()/2.0 < -10))
        {
            S1.c.setX(S1.c.getX() + 1);
            willFit = S1.canFit(); // checks if the shape fits after the shift
        }
        if (willFit == true) return true; // if shape fits after shift, return true
    } //end while loop for X
    /* this loop shifts Y co-ordinate until the side no longer
    surpasses the 20x10 grid bounds */
    while ((S1.c.getY() + S1.getSide()/2) > 5 || (S1.c.getY() - S1.getSide()/2.0) < -5)
    {
        // shifts Y one unit down if the side passes the upper edge of grid
        if (S1.c.getY() > 0 && (S1.c.getY() + S1.getSide()/2.0) > 5)
        {
            S1.c.setY(S1.c.getY() - 1);
            willFit = S1.canFit(); // checks if the shape fits after the shift
        }
        // shifts Y one unit up if the side passes the bottom edge of grid
        else if (S1.c.getY() < 0 && (S1.c.getY() - S1.getSide()/2.0 < -5))
        {
            S1.c.setY(S1.c.getY() + 1);
            willFit = S1.canFit(); // checks if the shape fits after the shift
        }
        if (willFit == true) return true; // checks if the shape fits after the shift
    } //end while loop for X
    return false;
}

bool canBeRecentered(Rectangle &R1)
{
    // this will be used to see whether the shape needs to be shifted
    bool willFit = R1.canFit();
    // early condition checks
    if (willFit == true) return true;
    if (R1.getLength() > 20 || R1.getWidth() > 10) return false;
    // setting reasonable values for the co-ordinates
    if (R1.c.getX() <= -10) R1.c.setX(-9);  // if X too far left, shift to right bound
    if (R1.c.getX() >= 10) R1.c.setX(9);    // if X too far right, shift to left bound
    if (R1.c.getY() <= -5) R1.c.setY(-4);   // if Y too far down, shift to lower bound
    if (R1.c.getY() >= 5) R1.c.setY(4);     // if Y too far up, shift to upper bound
    /* this loop shifts X co-ordinate until the length no longer
    surpasses the 20x10 grid bounds */
    while (((R1.c.getX() + R1.getLength()/2.0 > 10) || (R1.c.getX() - R1.getLength()/2.0 < -10)))
    {
        // shifts X one to the left if the length passes the right edge of grid
        if (R1.c.getX() > 0 && (R1.c.getX() + R1.getLength()/2.0) > 10)
        {
            R1.c.setX(R1.c.getX() - 1);
            willFit = R1.canFit(); // checks if the shape fits after shift
        }
        // shifts X one to the right if the length passes the left edge of grid
        else if (R1.c.getX() < 0 && (R1.c.getX() - R1.getLength()/2.0 < -10))
        {
            R1.c.setX(R1.c.getX() + 1);
            willFit = R1.canFit(); // checks if shape fits after shift
        }
        if (willFit == true) return true; // if shape fits after shift return true
    } //end while loop for X
    /* this loop shifts Y co-ordinate until the width no longer
    surpasses the 20x10 grid bounds */
    while ((R1.c.getY() + R1.getWidth()/2) > 5 || (R1.c.getY() - R1.getWidth()/2.0) < -5)
    {
        // shifts X one unit down if the width passes the upper edge of grid
        if (R1.c.getY() > 0 && (R1.c.getY() + R1.getWidth()/2.0) > 5)
        {
            R1.c.setY(R1.c.getY() - 1);
            willFit = R1.canFit(); // checks if shape fits after shift
        }
        // shifts X one unit up if the width passes the bottom edge of grid
        else if (R1.c.getY() < 0 && (R1.c.getY() - R1.getWidth()/2.0 < -5))
        {
            R1.c.setY(R1.c.getY() + 1);
            willFit = R1.canFit(); // checks if the shape fits after shift
        }
        if (willFit == true) return true;  // if shape fits after shift, return true
    } //end while loop for X
    return false;
}
