/*
* test.cpp
* Test driver for the project
* Author: Justin Ventura
* Created: September 18, 2019
* Current: September 27, 2019
*/

#include "shape.h"
#include "rect.h"
#include "square.h"
#include "circle.h"
#include "shapeTryRecenter.h"
#include "drawShape.h"
#include <iostream>

int main()
{
    /* first we prompt the user to select a shape that they
    want to be added. if their input is incorrect then the
    program will display an error message and ask them again.
    */
    enum SHAPE_TYPE { rect = 0, square, circle };
    SHAPE_TYPE shapeType;
    Rectangle R;
    Square S;
    Circle C;

    bool run_program = true;
    while(run_program)
    {
        char choice = 0; // used to store the answer choice they give
        std::cout << "============================================\n";
        // this do...while is used to ensure valid entries
        // using char so that a letter wont crash program
        do {
            std::cout << "     Which shape would you like to add?     \n";
            std::cout << "   (1) Rectangle/Square       (2) Circle    \n";
            std::cout << "            --> ";
            std::cin.get(&choice, 1);
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "\n-------------Invalid input.----------------\n\n";
            }
        } while(choice != '1' && choice != '2');

        /* now we will check which shape they used and create
        the shape with the characteristics that they choose.
        it will also check whether or not the shape will fit
        on the 20x10 grid. loops in case of error.
        */

        while (true)
        {
            // switch for different shapes
            switch (choice)
            {
                // used for input validation
                case '1': // case for rect/square
                {
                    /* READ USER INPUT FOR THE RECT/SQUARE */
                    int x, y;
                    char trash; // catch parentheses and comma
                    float l, w;     // length and width
                    std::cout << "============================================\n";
                    std::cout << "  Form of co-ordinates: (x, y) --> 0, 5     \n";
                    while(true)
                    {
                        try
                        {
                            std::cout << "            --> ";
                            std::cin >> x >> trash >> y;
                            if (!std::cin)
                            {
                                std::string invalid_entry = "      [ERROR: x & y must be integers.]\n";
                                throw invalid_entry;
                            }
                            else break;
                        }
                        catch (std::string invalid_entry)
                        {
                            std::cerr << invalid_entry;
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                    std::cout << std::endl;
                    std::cout << "  Form of length/width: (l, w) --> 2, 6     \n";
                    // this while ensures that length and width are valid choices
                    while(true)
                    {
                        try
                        {
                            std::cout << "            --> ";
                            std::cin >> l >> trash >> w;
                            // catches non-valid inputs
                            if (!std::cin)
                            {
                                std::string invalid_entry = "      [ERROR: l & w must be numbers.]\n";
                                throw invalid_entry;
                            }
                            if (l <= 0 || w <= 0)
                            {
                                std::cout << "Invalid input: length/width must be greater than 0.\n";
                                std::cout << "         Please re-enter a valid value             \n";
                                continue;
                            }
                            break;
                        }
                        catch (std::string invalid_entry)
                        {
                            std::cerr << invalid_entry;
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                    /* IF LENGTH == WIDTH, THEN RECTANGLE IS A SQUARE */
                    if (l == w)
                    {
                        std::cout << "\n            Creating a square...             \n\n";
                        shapeType = square; // now program knows square is being made
                        // here the square is now set with the given side and co-ordinates
                        S.setSide(l);
                        S.setCenter(x, y);
                    }
                    /* IF LENGTH != WIDTH, THEN RECTANGLE IS NOT A SQUARE */
                    else
                    {
                        std::cout << "\n          Creating a rectangle...            \n\n";
                        shapeType = rect;  // now program knows rectangle is being made
                        // here the rect is now set with the given length/width and co-ordinates
                        R.setDimensions(l, w);
                        R.setCenter(x, y);
                    }
                    std::cout << "============================================\n";
                    break;
                }
                case '2': // case for circle
                {
                    /* READ USER INPUT FOR THE RECT/SQUARE */
                    int x, y;
                    char trash;
                    float r;        // radius
                    std::cout << "============================================\n";
                    std::cout << "  Form of co-ordinates: (x, y) --> 0, 5   \n";
                    while(true)
                    {
                        try
                        {
                            std::cout << "            --> ";
                            std::cin >> x >> trash >> y;
                            if (!std::cin)
                            {
                                std::string invalid_entry = "     [ERROR: x & y must be integers.]\n";
                                throw invalid_entry;
                            }
                            else break;
                        }
                        catch (std::string invalid_entry)
                        {
                            std::cerr << invalid_entry;
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                    std::cout << "  Form of radius: r --> 3                   \n";
                    // this do...while ensures that the radius is a valid choice
                    while(true)
                    {
                        try
                        {
                            std::cout << "            --> ";
                            std::cin >> r;
                            // catches non-valid inputs
                            if (!std::cin)
                            {
                                std::string invalid_entry = "      [ERROR: r must be a number.]\n";
                                throw invalid_entry;
                            }
                            if (r <= 0)
                            {
                                std::cout << "Invalid input: radius must be greater than 0.\n";
                                std::cout << "       Please re-enter a valid value         \n";
                                continue;
                            }
                            break;
                        }
                        catch (std::string invalid_entry)
                        {
                            std::cerr << invalid_entry;
                            std::cin.clear();
                            std::cin.ignore();
                        }
                    }
                    std::cout << "\n          Creating a circle...            \n";
                    std::cout << "============================================\n";
                    shapeType = circle; // now program knows to test a circle
                    // here the circle is now set with the given radius and co-ordinates
                    C.setRadius(r);
                    C.setCenter(x, y);
                    break;
                }
            } //end switch

            // this will be used to determine if the shape can ever be recentered to fit
            bool flag = false;

            /* THIS IS THE STRUCTURE WHICH WILL TEST IF THE SELECTED SHAPE WITH
            THE GIVEN CHARACTERISTICS WILL FIT, IF IT DOES NOT FIT, THE PROGRAM
            WILL ATTEMPT TO RELOCATE THE CENTER.  IF IT STILL DOES NOT FIT, THEN
            THE PROGRAM WILL THROW AN ERROR AND REPROMPT USER */
            switch (shapeType)
            {
                case rect:   // case for the circle shape
                {
                    // checks if shape can already fit
                    flag = R.canFit();
                    // if shape fits, display the stats
                    if (flag)
                    {
                        std::cout << "         The shape fits on grid!             \n";
                        R.displayStats();
                        drawShape(R);
                        break;
                    }
                    else // if the shape doesnt fit, attempt to relocate the center
                    {
                        // checks if the shape can be recentered or not
                        try
                        {
                            flag = canBeRecentered(R);
                            // if it can fit, display new stats of the shape
                            if (flag)
                            {
                                std::cout << "         The shape fits on grid!             \n";
                                std::cout << "       (Center has been relocated)           \n";
                                R.displayStats();
                                drawShape(R);
                                break;
                            }
                            else
                            {
                                // creates and throws an error string if shape does not fit
                                std::string shape_does_not_fit = "\n      ERROR: Shape does not fit in grid.\n";
                                throw shape_does_not_fit;
                            }
                        } //end try block
                        // this catches a shape that does not fit on the grid
                        catch (std::string shape_does_not_fit)
                        {
                            // states error, tehen promts user to re-enter data
                            std::cerr << shape_does_not_fit;
                            std::cerr << "          Please re-enter data.         \n\n";
                            continue;
                        }
                    } // end else for fit check
                    break;
                } // end case rectangle
                case square: // case for the circle shape
                {
                    // checks if shape can already fit
                    flag = S.canFit();
                    // if shape fits, display the stats
                    if (flag)
                    {
                        std::cout << "         The shape fits on grid!             \n";
                        S.displayStats();
                        drawShape(S);
                        break;
                    }
                    else // if the shape doesnt fit, attempt to relocate the center
                    {
                        // checks if the shape can be recentered or not
                        try
                        {
                            flag = canBeRecentered(S);
                            // if it can fit, display new stats of the shape
                            if (flag)
                            {
                                std::cout << "         The shape fits on grid!             \n";
                                std::cout << "       (Center has been relocated)           \n";
                                S.displayStats();
                                drawShape(S);
                                break;
                            }
                            else
                            {
                                // creates and throws an error string if shape does not fit
                                std::string shape_does_not_fit = "\n      ERROR: Shape does not fit in grid.\n";
                                throw shape_does_not_fit;
                            }
                        } //end try block
                        // this catches a shape that does not fit on the grid
                        catch (std::string shape_does_not_fit)
                        {
                            // states error, tehen promts user to re-enter data
                            std::cerr << shape_does_not_fit;
                            std::cerr << "          Please re-enter data.         \n\n";
                            continue;
                        }
                    } // end else for fit check
                    break;
                } //end case square
                case circle: // case for the circle shape
                {
                    // checks if shape can already fit
                    flag = C.canFit();
                    // if shape fits, display the stats
                    if (flag)
                    {
                        std::cout << "         The shape fits on grid!             \n";
                        C.displayStats();
                        drawShape(C);
                        break;
                    }
                    else // if the shape doesnt fit, attempt to relocate the center
                    {
                        // checks if the shape can be recentered or not
                        try
                        {
                            flag = canBeRecentered(C);
                            // if it can fit, display new stats of the shape
                            if (flag)
                            {
                                std::cout << "         The shape fits on grid!             \n";
                                std::cout << "       (Center has been relocated)           \n";
                                C.displayStats();
                                drawShape(C);
                                break;
                            }
                            else
                            {
                                // creates and throws an error string if shape does not fit
                                std::string shape_does_not_fit = "\n      ERROR: Shape does not fit in grid.\n";
                                throw shape_does_not_fit;
                            }
                        } //end try block
                        // this catches a shape that does not fit on the grid
                        catch (std::string shape_does_not_fit)
                        {
                            // states error, tehen promts user to re-enter data
                            std::cerr << shape_does_not_fit;
                            std::cerr << "          Please re-enter data.         \n\n";
                            continue;
                        }
                    } // end else for fit check
                    break;
                } //end case circle block

                default: std::cout << "Error." << std::endl;

            } // end choice switch
            break;
        } //end while loop
        // PROMPT USER ASKING IF THEY WILL RUN AGAIN.
        char runChoice;
        std::cout << "Would you like to try another shape? y/n: ";

        do{
            std::cin >> runChoice;
            std::cin.ignore();
            if (runChoice != 'y' && runChoice != 'n') std::cout << "Invalid response. Press y or n: ";
        } while (runChoice != 'y' && runChoice != 'n');

        if (runChoice == 'n') run_program = false;

    } // end of program

    std::cout << "\n  Thank you for running Justin Ventura's \n";
    std::cout << "            Shape Plot software!           \n";
    std::cout << "============================================\n";

    return 0;

} //end main()
