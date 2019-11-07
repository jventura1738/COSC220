/*
Pointers.cpp
COSC-220 Lab 9
*/

#include <iostream>
#include <stddef.h>     // for NULL definition

int main()
{

    int int1 = 1, int2 = 2, int3 = 3;
    double dub1 = 1.0, dub2 = 2.0, dub3 = 3.0;
    float flt1 = 1.0f;
    char chr1 = 'a', chr2 = 'b';

    //////////////////////////////////////////////////////////////////
    // 1. Experiment with storage sizes and addresses of various data
    // types.
    //////////////////////////////////////////////////////////////////
    //  A.  Add statements to print the addresses of each of the 9
    //  variables declared above and record the addresses.
    //  B.  Add statements to print the sizes (in bytes) of each of the
    //  9 variables  (use the sizeof operator).
    //  C.  Add statements to print the sizes of the addresses of the 9
    //  variables (again, use the sizeof operator).

    //  Write your code here:
    std::cout << "addresses: \n";
    std::cout << &int1 << " | " << &int2 << " | " << &int3 << "\n";
    std::cout << &dub1 << " | " << &dub2 << " | " << &dub3 << "\n";
    std::cout << &flt1 << "\n";
    std::cout << static_cast<void *>(&chr1) << " | " << static_cast<void *>(&chr2) << "\n";

    std::cout << "sizes (bytes): \n";
    std::cout << sizeof(int1) << " | " << sizeof(int2) << " | " << sizeof(int3) << "\n";
    std::cout << sizeof(dub1) << " | " << sizeof(dub2) << " | " << sizeof(dub3) << "\n";
    std::cout << sizeof(flt1) << "\n";
    std::cout << sizeof(chr1) << " | " << sizeof(chr2) << "\n";

    std::cout << "size of refs (bytes): \n";
    std::cout << sizeof(&int1) << " | " << sizeof(&int2) << " | " << sizeof(&int3) << "\n";
    std::cout << sizeof(&dub1) << " | " << sizeof(&dub2) << " | " << sizeof(&dub3) << "\n";
    std::cout << sizeof(&flt1) << "\n";
    std::cout << sizeof(&chr1) << " | " << sizeof(&chr2) << "\n";

    std::cout << "-----------------------------------------" << "\n\n";

    // Record your results here:
    //
    //  Variable  Size   Address   Address-Size
    //   int1      4 | 0x7fff1e0741bc | 8
    //   int2      4 | 0x7fff1e0741b8 | 8
    //   int3      4 | 0x7fff1e0741b4 | 8
    //   dub1      8 | 0x7fff1e0741a8 | 8
    //   dub2      8 | 0x7fff1e0741a0 | 8
    //   dub3      8 | 0x7fff1e074198 | 8
    //   flt1      4 | 0x7fff1e074194 | 8
    //   chr1      1 | 0x7ffec2116fd3 | 8
    //   chr2      1 | 0x7ffec2116fd3 | 8


    // How many bytes of storage is allocated for each data type?  How
    // many bytes is allocated for each pointer (address). Notice that
    // the data types are not necessarily the same size, but the
    // pointers are.
    //
    // Did the address of the char variables print as you expected?  If
    // not, why not?   You can force the printed output to be
    // interpreted as a pointer by coercing it (casting) to void* like
    // this:
    //    cout << (void *) &chr1;
    //
    // Run the program again, using the coercion for the char
    // pointers. Record your data.

    // Write your modified code here:

    // ALREADY DID THIS //

    // Record your results here:
    //
    //  Variable  Size   Address   Address-Size
    //     chr1
    //     chr2

    //////////////////////////////////////////////////////////////////
    // 2. Experiment with pointer variables.
    //////////////////////////////////////////////////////////////////
    //   A. Declare pointer vaiables intPtr1, intPtr2, intPtr3, dubPtr1,
    //   dubPtr2, dubPtr3, fltPtr1, chrPtr1, and chrPtr2 so that they
    //   can be used to point to the  appropriate variables.  Assign the
    //   address of the appropriate variable to them and print their
    //   values.  (The char pointers will have to be coerced as before
    //   for printing).

    //  Write your code here:
    int *intPtr1 = &int1, *intPtr2 = &int2, *intPtr3 = &int3;
    double  *dubPtr1 = &dub1, *dubPtr2 = &dub2, *dubPtr3 = &dub3;
    float *fltPtr1 = &flt1;
    char *chrPtr1 = &chr1, *chrPtr2 = &chr2;

    std::cout << "addresses (pointers): \n";
    std::cout << intPtr1 << " | " << intPtr2 << " | " << intPtr3 << "\n";
    std::cout << dubPtr1 << " | " << dubPtr2 << " | " << dubPtr3 << "\n";
    std::cout << fltPtr1 << "\n";
    std::cout << static_cast<void *>(chrPtr1) << " | " << static_cast<void *>(chrPtr2) <<  "\n\n";

    std::cout << "-----------------------------------------" << "\n\n";

    //  Report your results here:
    //
    //   Pointer  Printed
    //  Variable   Value
    //   intPtr1 0x7fff2092d064 | 4
    //   intPtr2 0x7fff2092d060 | 4
    //   intPtr3 0x7fff2092d05c | 4
    //   dubPtr1 0x7fff2092d050 | 8
    //   dubPtr2 0x7fff2092d048 | 8
    //   dubPtr3 0x7fff2092d040 | 8
    //   fltPtr1 0x7fff2092d03c | 4
    //   chrPtr1 0x7fff2092d03b | 1
    //   chrPtr2 0x7fff2092d03a | 1

    // How do the values of the pointers compare to the values of the
    // addresses you got in the previous experiment?

    // they are the same buddy

    //////////////////////////////////////////////////////////////////
    //  3. Experiments with NULL pointers and with dereferencing
    //////////////////////////////////////////////////////////////////
    //   A. Assign NULL to fltPtr1, then print the value of fltPtr1.
    //   B. Accessing the storage locations through the relevant
    //   pointers, assign the following values and print them.
    //       int1  12
    //       int2  22
    //       dub1  10.1
    //       dub2  20.2
    //       flt1  30.3

    // Write your code here:

    // gotem

    // Your program should have terminated with a run-time error.
    // What error was reported?
    //
    //
    //
    // Why did it occur?
    //
    // e

    //   C.  Fix the problem and repeat.

    // Write your code here:


    //////////////////////////////////////////////////////////////////
    //  4. Experiments with pointer arithmetic
    //////////////////////////////////////////////////////////////////
    //    A.  Print the values of intPtr2, (intPtr2+1) and
    //    (intPtr2-1). Did you get what you expected?

    // Write your code here:

    std::cout << (intPtr2) << " | " << (intPtr2 + 1) << " | " << (intPtr2 -1) << "\n\n";

    // Write your explanation here:
    // no


    //   B. Print the value of intPtr1.
    //   C. Use the increment operator to increment intPtr1.
    //   D. Print the value of intPtr1 again.
    //   E. Print the value of the memory location pointed to by
    //   intPtr1.  Explain what is happening.

    // Write your code here:

    std::cout << *intPtr1 << "\n";
    intPtr1++;
    std::cout << *intPtr1 << "\n";
    std::cout << intPtr1 << "\n";

    // Write your explanation here.
    //
    // random number bc random Address
    //
    //

    std::cout << "-----------------------------------------" << "\n\n";


    //////////////////////////////////////////////////////////////////
    //  5. Experiments with dynamic allocation
    //////////////////////////////////////////////////////////////////
    //   A.  Use the new operator to dynamically allocate an integer.
    //   B.  Assign the number 6000 to the new location.
    //   C.  Print the address of this new location.
    //   D.  Print the value stored in the new location.
    //   E.  Comment on the address of the new location compared to the
    //   addresses seen in part 2.

    //  Write your code here:

    int *val =  new int;
    *val = 6000;
    std::cout << val << "\n";
    std::cout << *val << "\n";

    //  Write your results and comments here:
    //
    //  new location address = 0xa02010
    //  contents of new location = 6000

    //  Comment:
    // way different

    //  F.  Use the new operator to allocate an array of size 10 of
    //  doubles.  Fill the array with 10.0,20.0,...100.0 and print the array.

    // Write your code here:

    double *arr = new double [10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = (i + 1)*10.0;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << "\n";
    }

    return 0;
}
