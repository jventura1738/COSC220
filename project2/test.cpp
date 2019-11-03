#include "Sorts.h"
#include "timer.h"
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>

/* enums to specify an order */
enum element_order { RANDOM = 0, ASCEND, DESCEND };

// ARRAY GENERATE - INTEGERS (generates an array)
// Pre: specify a valid order and size
// Post: generates a dynamically allocated array depending on args
// Returns: pointer to a dynamically allocated array
int *array_generate (element_order, int);

// PRINT ARRAY (prints an array)
// Pre: a non-empty array
// Post: prints the array to console
// Returns: nothing, prints array
template <typename T>
void print_array (T& array, int size);

int main()
{
    Timer timer; // timer object
    element_order order; // order enum
    int *arr; // pointer to an array
    int trial_count = 1; // count trial type
    /*  TOOLS FROM MY TIMER CLASS
        timer.start_timer();
        timer.end_timer();
        timer.display_time();
        timer.reset_time();
        timer.get_time();
    */
    std::cout << "========================================\n";
    std::cout << "               BUBBLE SORT              \n";
    std::cout << "========================================\n";
    std::cout << "Initial sequence: \n";
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    bubble_sort_demo(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    std::cout << "========================================\n";
    delete arr; // prevent memory leaks
    arr = nullptr;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 12;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            bubble_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    trial_count = 1;
    std::cout << "========================================\n";
    std::cout << "            SELECTION SORT              \n";
    std::cout << "========================================\n";
    std::cout << "Initial sequence: \n";
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    selection_sort_demo(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    std::cout << "========================================\n";
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 12;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            selection_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    trial_count = 1;
    std::cout << "========================================\n";
    std::cout << "            INSERTION SORT              \n";
    std::cout << "========================================\n";
    std::cout << "Initial sequence: \n";
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    insertion_sort_demo(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    std::cout << "========================================\n";
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 12;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            insertion_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    trial_count = 1;
    std::cout << "========================================\n";
    std::cout << "          DE-SELECTION SORT             \n";
    std::cout << "========================================\n";
    std::cout << "Initial sequence: \n";
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    double_selection_sort_demo(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    std::cout << "========================================\n";
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 12;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            double_selection_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    trial_count = 1;
    std::cout << "========================================\n";
    std::cout << "             EXCHANGE SORT              \n";
    std::cout << "========================================\n";
    std::cout << "Initial sequence: \n";
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    exchange_sort_demo(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    std::cout << "========================================\n";
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 12;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            exchange_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    // MERGE SORT
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    merge_sort(arr, 0, 15);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 16;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            merge_sort(arr, 0, pow(2, power) - 1);
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    // HEAP SORT
    arr = array_generate(RANDOM, 16);
    print_array(arr, 16);
    heap_sort(arr, 16);
    std::cout << "\nFinal sequence: \n";
    print_array(arr, 16);
    delete arr; // prevent memory leaks
    arr = NULL;
    while (trial_count <= 3)
    {
        int sample = 1;
        int power = 16;
        std::cout << "\nSorting array of size 2^" << power << "... 5 trials:\n";
        if (trial_count == 1)
        {
            order = RANDOM;
            std::cout << "Order: random.\n";
        }
        else if (trial_count == 2)
        {
            order = DESCEND;
            std::cout << "Order: descending.\n";
        }
        else
        {
            order = ASCEND;
            std::cout << "Order: ascending.\n";
        }
        while(sample <= 5)
        {
            arr = array_generate(order, pow(2, power));
            timer.start_timer();
            heap_sort(arr, pow(2, power));
            timer.end_timer();
            timer.display_time();
            timer.reset_time();
            delete arr;
            arr = NULL;
            sample++;
        }
        trial_count++;
    }
    return 0;
}

int *array_generate (element_order ORDER, int size)
{
    int* array = new int[size];
    if (ORDER == RANDOM)
    {
        for (int i = 0; i < size; i++)
        {
            *(array + i) = (i + 1);
        }
        // generates a random seed for the random engine
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(array, array + size, std::default_random_engine(seed));
        return array;
    }
    else if (ORDER == ASCEND)
    {
        for (int i = 0; i < size; i++)
        {
            *(array + i) = (i + 1);
        }
        return array;
    }
    else if (ORDER == DESCEND)
    {
        int j = size - 1;
        for (int i = 0; i < size; i++)
        {
            *(array + i) = j;
            --j;
        }
        return array;
    }
    else
    {
        std::cout << "ERROR" << "\n";
    }
}

template <typename T>
void print_array (T& array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}
