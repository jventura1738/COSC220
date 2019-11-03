/*
 * drawShape.cpp
 * Implementation of the drawShape helper functions
 * Author: Justin Ventura
 * Created: September 21, 2019
 * Current: September 28, 2019
*/

#include "drawShape.h"
#include <iostream>

void drawShape(const Circle &C1)
{
	if (C1.getRadius() < 0 || C1.getRadius() > 5)
	{
		std::cout << "ERROR: invalid radius.\n";
		return;
	}
	/* ESTABLISH A PLANE (row = y, col = x) */
	char plane[11][41];
	for (int i = 0; i < 11; i++)
	{
		// prints y from top to bottom
		// prints x from left to right
		for (int j = 0; j < 41; j++)
		{
			if (i == 5 && j%2 == 0) plane[5][j] = '*';
			else if (i == 5 && j%2 != 0) plane[5][j] = ' ';
			else plane[i][j] = ' ';
		}
		plane[i][20] = '*';
	} // 231 iterations

	/* DRAW THE SHAPE ACCORDINGLY */
	// step 1: set origin val for reference
	int origin_x = 20; // this index for X
	int origin_y = 5;  // this index for Y
	int radius   = C1.getRadius();

	// step 2: convert pass origin to grid
	origin_x += (2*C1.c.getX());     // x is spaced so scale by 2
	origin_y -= C1.c.getY();	     // subtract; top->bot
	plane[origin_y][origin_x] = '+'; // place origin

	// step 3: draw 4 corners using radius
	plane[origin_y - radius][origin_x] = 'o'; // top
	plane[origin_y][origin_x - 2*radius] = 'o'; // left
	plane[origin_y][origin_x + 2*radius] = 'o'; // right
	plane[origin_y + radius][origin_x] = 'o'; // bottom

	// step 4: draw edges
	if (radius < 5)
	{
		// if radius < 5, add 4 edges
		plane[origin_y - (radius - 1)][origin_x - (radius + 1)] = 'o';
		plane[origin_y - (radius - 1)][origin_x + (radius + 1)] = 'o';
		plane[origin_y + (radius - 1)][origin_x - (radius + 1)] = 'o';
		plane[origin_y + (radius - 1)][origin_x + (radius + 1)] = 'o';
	}
	else
	{
		// if radius == 5, add 8 edges
		plane[origin_y - (radius - 1)][origin_x - (radius)] = 'o';
		plane[origin_y - (radius - 1)][origin_x + (radius)] = 'o';
		plane[origin_y + (radius - 1)][origin_x - (radius)] = 'o';
		plane[origin_y + (radius - 1)][origin_x + (radius)] = 'o';
		plane[origin_y - 2][origin_x - 8] = 'o';
		plane[origin_y + 2][origin_x - 8] = 'o';
		plane[origin_y - 2][origin_x + 8] = 'o';
		plane[origin_y + 2][origin_x + 8] = 'o';
	}

	/* PRINT THE SHAPE TO TERMINAL */
	std::cout << "============================================\n";
	std::cout << " '*' is axis, '+' is center, 'o' is an edge \n";
	std::cout << "============================================\n";
	std::cout << "     Approximate shape location on grid:    \n";
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			std::cout << plane[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "============================================\n";
	// and it's done! took forever to plan this
}

void drawShape(const Square &S1)
{
	if (S1.getSide() < 0 || S1.getSide() > 10)
	{
		std::cout << "ERROR: Invalid side value.\n";
		return;
	}
	/* ESTABLISH A PLANE (row = y, col = x) */
	char plane[11][41];
	for (int i = 0; i < 11; i++)
	{
		// prints y from top to bottom
		// prints x from left to right
		for (int j = 0; j < 41; j++)
		{
			if (i == 5 && j%2 == 0) plane[5][j] = '*';
			else if (i == 5 && j%2 != 0) plane[5][j] = ' ';
			else plane[i][j] = ' ';
		}
		plane[i][20] = '*';
	} // 231 iterations

	/* DRAW THE SHAPE ACCORDINGLY */
	// step 1: set origin val for reference
	int origin_x = 20; // this index for X
	int origin_y = 5;  // this index for Y
	int side = S1.getSide();

	// step 2: convert pass origin to grid
	origin_x += (2*S1.c.getX());     // x is spaced so scale by 2
	origin_y -= S1.c.getY();	     // subtract; top->bot
	plane[origin_y][origin_x] = '+'; // place origin

	// step 3: draw 4 corners using side
	if (side > 2)
	{
		plane[origin_y - (side/2)][origin_x - (side - 1)] = 'o'; // top/left
		plane[origin_y - (side/2)][origin_x + (side - 1)] = 'o'; // top/right
		plane[origin_y + (side/2)][origin_x - (side - 1)] = 'o'; // bot/left
		plane[origin_y + (side/2)][origin_x + (side - 1)] = 'o'; // bot/right
	}

	// step 4: draw edges
	if (side >= 5)
	{
		std::cout << "big gay";
		plane[origin_y - side/2][origin_x] = 'o';
		plane[origin_y + side/2][origin_x] = 'o';
		plane[origin_y][origin_x - (side - 1)] = 'o';
		plane[origin_y][origin_x + (side - 1)] = 'o';
	}

	/* PRINT THE SHAPE TO TERMINAL */
	std::cout << "============================================\n";
	std::cout << " '*' is axis, '+' is center, 'o' is an edge \n";
	std::cout << "============================================\n";
	std::cout << "     Approximate shape location on grid:    \n";
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			std::cout << plane[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "============================================\n";
	// finally done
}

void drawShape(const Rectangle &R1)
{
	if (R1.getLength() > 20 || R1.getWidth() > 10)
	{
		std::cout << "ERROR: Invalid length/width value.\n";
		return;
	}
	/* ESTABLISH A PLANE (row = y, col = x) */
	char plane[11][41];
	for (int i = 0; i < 11; i++)
	{
		// prints y from top to bottom
		// prints x from left to right
		for (int j = 0; j < 41; j++)
		{
			if (i == 5 && j%2 == 0) plane[5][j] = '*';
			else if (i == 5 && j%2 != 0) plane[5][j] = ' ';
			else plane[i][j] = ' ';
		}
		plane[i][20] = '*';
	} // 231 iterations

	/* DRAW THE SHAPE ACCORDINGLY */
	// step 1: set origin val for reference
	int origin_x = 20; // this index for X
	int origin_y = 5;  // this index for Y
	int length = R1.getLength();
	int width  = R1.getWidth();

	// step 2: convert pass origin to grid
	origin_x += (2*R1.c.getX());     // x is spaced so scale by 2
	origin_y -= R1.c.getY();	     // subtract; top->bot
	plane[origin_y][origin_x] = '+'; // place origin

	// step 3: draw 4 corners using length&width
	if (length <= 2)
	{
		for (int i = (origin_y - width/2); i < (origin_y + width/2); i++)
		{
			plane[i][origin_x] = 'o';
		}
	}
	else if (width <= 2)
	{
		for (int i = (origin_x - length); i < (origin_x + length) ; i++)
		{
			if (i%2 == 0) plane[origin_y][i] = 'o';
		}
	}
	if (length > 2 && width > 2)
	{
		plane[origin_y - (width/2)][origin_x - (length - 1)] = 'o'; // top/left
		plane[origin_y - (width/2)][origin_x + (length - 1)] = 'o'; // top/right
		plane[origin_y + (width/2)][origin_x - (length - 1)] = 'o'; // bot/left
		plane[origin_y + (width/2)][origin_x + (length - 1)] = 'o'; // bot/right
	}

	// step 4: draw edges
	if (length > 5 && width > 5)
	{
		plane[origin_y - width/2][origin_x] = 'o';
		plane[origin_y + width/2][origin_x] = 'o';
		plane[origin_y][origin_x - (length - 1)] = 'o';
		plane[origin_y][origin_x + (length - 1)] = 'o';
	}
	/* PRINT THE SHAPE TO TERMINAL */
	std::cout << "============================================\n";
	std::cout << " '*' is axis, '+' is center, 'o' is an edge \n";
	std::cout << "============================================\n";
	std::cout << "     Approximate shape location on grid:    \n";
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			std::cout << plane[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "============================================\n";
	// the hardest one to plan
}
