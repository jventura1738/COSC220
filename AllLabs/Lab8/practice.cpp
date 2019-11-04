#include <iostream>

int count_occur_arr(int*, int, int);
int count_occur(int, int);

int main()
{
    std::cout << "\nHow many 2s in set: ";
    std::cout << "2, 4, 2, 6, 3, 2? --> ";
    int arr [] = {2, 4, 2, 6, 3, 2};
    std::cout << count_occur_arr(arr, 9, 2) << "\n\n";

    int test = 394735638;
    std::cout << "How many 3's in " << test << "? --> ";
    std::cout << count_occur(test, 3) << "\n\n";
    return 0;
}

int count_occur_arr(int *array, int size, int key)
{
    if (size == 0) return 0;
    if (array[size - 1] != key) return count_occur_arr(array, size - 1, key);
    else return 1 + count_occur_arr(array, size - 1, key);
}

int count_occur(int input, int key)
{
    if (input == 0) return 0;
    if (input % 10 != key) return count_occur(input / 10, key);
    else return 1 + count_occur(input / 10, key);
}
