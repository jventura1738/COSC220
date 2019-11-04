// Justin Ventura COSC220-003
// LAB9: lab9Driver.cpp
//////////   THIS CODE IS PROVIDED TO STUDENTS   /////////////

#include "lab9aux.h"
#include <vector>
#include <iostream>

// Put a bunch of integer values into vect
void fillVector(std::vector<int> & vect);

int main()
{
    using namespace std;

    // Declare an empty vector of int
    vector<int> vect;

    ///////////////  Test removeDup ///////////////
    // Fill vect with values and write it out
    fillVector(vect);
    cout << "Testing removeDup" << endl;
    cout << "Original vector is  ";
    writeVector(vect);

    // Remove the duplicates and write it out again
    removeDup(vect);
    cout << "Vector with duplicates removed is  ";
    writeVector(vect);
    cout << endl;

    ///////////////  Test removeDup2 ///////////////
    // Fill it with values again and write it out
    fillVector(vect);
    cout << "Testing removeDup2" << endl;
    cout << "Original vector is  ";
    writeVector(vect);

    // Remove the duplicates and write it out again
    removeDup2(vect);
    cout << "Vector with duplicates removed is  ";
    writeVector(vect);
    cout << endl;

    ///////////////  Test removeDup3 ///////////////
    // Fill it with values again and write it out
    fillVector(vect);
    cout << "Testing removeDup3" << endl;
    cout << "Original vector is  ";
    writeVector(vect);

    // Remove the duplicates and write it out again
    removeDup3(vect);
    cout << "Vector with duplicates removed is  ";
    writeVector(vect);

    return 0;
}


void fillVector(std::vector<int> & vect)
{
    int arr[] = {1,7,2,7,9,1,2,8,9};
    unsigned arrsize = sizeof(arr)/sizeof(int);

    vect = std::vector<int>(arr, arr+arrsize);
}
