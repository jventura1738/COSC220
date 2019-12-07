# COSC220 Project 1: Shape Fitting & Draw

Justin Ventura.


## Specifications.

This program will take input from the user which will be the shape (circle, square, rectangle), then it's dimensions (center, radius, length, and width).  Once the data is collected, the program will attempt to fit the shape on a 20x10 x-y plane.  If the shape is too big to fit, the program will re-prompt the user to enter new dimensions.  If the shape can fit but needs to be re-centered, then it will be re-centered to the closest valid position on the plane and display the new center of the valid shape.  (This next addition i added for fun) If the shape fits, it will not only display the shape's stats, but it will draw the shape on the axis in the console.  This used no external libraries.


## Using the program

Using this program is relatively simple.  Type: 'make' to create the main executable.  Then ./main to run the program.  Simply enter the dimensions, then it will draw the shape in the console (if it fits).  If the shape does not fit, attempt to re-center.  If it cannot be re-centered, re-prompt dimensions.  Then you may try another shape if you so please. 
