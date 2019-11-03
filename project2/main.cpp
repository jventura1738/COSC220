#include "Sorts.h"
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>

/* enums to specify an order */
enum element_order { RANDOM = 0, ASCEND, DESCEND };

void dispOptions();

void redispOptions();

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

// GET CHOICE (recieves input as for int)
// Returns input integer
int getChoice();

int main()
{
    int choice = 0, option;
    Timer timer;
    dispOptions();
    int *sample = array_generate(RANDOM, 16);
    do
    {
        choice = getChoice();
        switch (choice)
        {
            case 1:
            std::cout << "Sorting 16 unique elements; Random -> Ascending.  \n";
            std::cout << "==================================================\n";
            std::cout << "                   BUBBLE SORT                    \n";
            std::cout << "                   O(n^2), Ω(n)                   \n";
            std::cout << "==================================================\n";
            std::cout << "Initial sequence: \n";
            sample = array_generate(RANDOM, 16);
            print_array(sample, 16);
            bubble_sort_demo(sample, 16);
            std::cout << "\nFinal sequence: \n";
            print_array(sample, 16);
            std::cout << "==================================================\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n^2), and space: O(1)          \n";
            std::cout << "Best case time: Ω(n), average: Θ(n^2)             \n";
            std::cout << "Fact: The beginners sort.                         \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                bubble_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n ";
                option = getChoice();
            }
            redispOptions();
            break;
            case 2:
            std::cout << "Sorting 16 unique elements; Random -> Ascending.  \n";
            std::cout << "==================================================\n";
            std::cout << "                  SELECTION SORT                  \n";
            std::cout << "                  O(n^2), Ω(n^2)                  \n";
            std::cout << "==================================================\n";
            std::cout << "Initial sequence: \n";
            sample = array_generate(RANDOM, 16);
            print_array(sample, 16);
            selection_sort_demo(sample, 16);
            std::cout << "\nFinal sequence: \n";
            print_array(sample, 16);
            std::cout << "==================================================\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n^2), and space: O(1)          \n";
            std::cout << "Best case time: Ω(n^2), average: Θ(n^2)           \n";
            std::cout << "Fact: Unstable but faster than bubble sort.       \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                selection_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n ";
                option = getChoice();
            }
            redispOptions();
            break;
            case 3:
            std::cout << "Sorting 16 unique elements; Random -> Ascending.  \n";
            std::cout << "==================================================\n";
            std::cout << "                  EXCHANGE SORT                   \n";
            std::cout << "                  O(n^2), Ω(n^2)                  \n";
            std::cout << "==================================================\n";
            std::cout << "Initial sequence: \n";
            sample = array_generate(RANDOM, 16);
            print_array(sample, 16);
            exchange_sort_demo(sample, 16);
            std::cout << "\nFinal sequence: \n";
            print_array(sample, 16);
            std::cout << "==================================================\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n^2), and space: O(1)          \n";
            std::cout << "Best case time: Ω(n^2), average: Θ(n^2)           \n";
            std::cout << "Fact: Better than bubble sort.                    \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                exchange_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n ";
                option = getChoice();
            }
            redispOptions();
            break;
            case 4:
            std::cout << "Sorting 16 unique elements; Random -> Ascending.  \n";
            std::cout << "==================================================\n";
            std::cout << "              DOUBLE SELECTION SORT               \n";
            std::cout << "                  O(n^2), Ω(n^2)                  \n";
            std::cout << "==================================================\n";
            std::cout << "Initial sequence: \n";
            sample = array_generate(RANDOM, 16);
            print_array(sample, 16);
            double_selection_sort_demo(sample, 16);
            std::cout << "\nFinal sequence: \n";
            print_array(sample, 16);
            std::cout << "==================================================\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n^2), and space: O(1)          \n";
            std::cout << "Best case time: Ω(n^2), average: Θ(n^2)           \n";
            std::cout << "Fact: Not very fast but cool idea.                \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                double_selection_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n ";
                option = getChoice();
            }
            redispOptions();
            break;
            case 5:
            std::cout << "Sorting 16 unique elements; Random -> Ascending.  \n";
            std::cout << "==================================================\n";
            std::cout << "                  INSERTION SORT                  \n";
            std::cout << "                   O(n^2), Ω(n)                   \n";
            std::cout << "==================================================\n";
            std::cout << "Initial sequence: \n";
            sample = array_generate(RANDOM, 16);
            print_array(sample, 16);
            insertion_sort_demo(sample, 16);
            std::cout << "\nFinal sequence: \n";
            print_array(sample, 16);
            std::cout << "==================================================\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n^2), and space: O(1)          \n";
            std::cout << "Best case time: Ω(n), average: Θ(n^2)             \n";
            std::cout << "Fact: Simple and fast.                            \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                insertion_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n";
                option = getChoice();
            }
            redispOptions();
            break;
            case 6:
            std::cout << "==================================================\n";
            std::cout << "Heap sort is too hard to demo and I'm not paid :) \n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n log n), and space: O(1)      \n";
            std::cout << "Best case time: Ω(n log n), average: Θ(n log n)   \n";
            std::cout << "Fact: Very good for large data sets.              \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                heap_sort(sample, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n";
                option = getChoice();
            }
            redispOptions();
            break;
            case 7:
            std::cout << "==================================================\n";
            std::cout << "Merge sort is too hard to demo and I'm not paid :)\n";
            std::cout << "Statistics:                                       \n";
            std::cout << "Worst case time: O(n log n), and space: O(n)      \n";
            std::cout << "Best case time: Ω(n log n), average: Θ(n log n)   \n";
            std::cout << "Fact: Arguably the fastest sort for arrays.       \n";
            std::cout << "==================================================\n";
            std::cout << "Push the limits of this sort and time it? (1) yes (2) no\n";
            option = getChoice();

            while(option == 1)
            {
                std::cout << "Sorting random array with 1,000,000 elements...\n";
                sample = array_generate(RANDOM, 1000000);
                timer.start_timer();
                merge_sort(sample, 0, 1000000);
                timer.end_timer();
                timer.display_time();
                std::cout << "Run large sample again? \n";
                option = getChoice();
            }
            redispOptions();
            break;
            case 8:
            std::cout << "\nThank you for using Justin Ventura's Sort Software!\n";
            break;
            case 9:
            dispOptions();
            default:
            std::cout << "Invalid choice. Press 9 to display options again.\n";
        }

    } while (choice != 8);

    return 0;
}

void dispOptions()
{
    std::cout << "==================================================\n";
    std::cout << "|                                                |\n";
    std::cout << "|   Welcome to Justin's sorting demo software!   |\n";
    std::cout << "|      Which sort would you like to demo?        |\n";
    std::cout << "|                                                |\n";
    std::cout << "|   1) Bubble Sort              O(n^2)           |\n";
    std::cout << "|   2) Selection Sort           O(n^2)           |\n";
    std::cout << "|   3) Exchange Sort            O(n^2)           |\n";
    std::cout << "|   4) Double Selection Sort    O(n^2)           |\n";
    std::cout << "|   5) Insertion Sort           O(n^2)           |\n";
    std::cout << "|   6) Heap Sort                O(nlogn)         |\n";
    std::cout << "|   7) Merge Sort               O(nlogn)         |\n";
    std::cout << "|   8) Exit Application         O(1)             |\n";
    std::cout << "|   9) Redisplay Options        O(1)             |\n";
    std::cout << "|                                                |\n";
    std::cout << "==================================================\n";
}

void redispOptions()
{
    std::cout << "==================================================\n";
    std::cout << "|                                                |\n";
    std::cout << "|   1) Bubble Sort              O(n^2)           |\n";
    std::cout << "|   2) Selection Sort           O(n^2)           |\n";
    std::cout << "|   3) Exchange Sort            O(n^2)           |\n";
    std::cout << "|   4) Double Selection Sort    O(n^2)           |\n";
    std::cout << "|   5) Insertion Sort           O(n^2)           |\n";
    std::cout << "|   6) Heap Sort                O(nlogn)         |\n";
    std::cout << "|   7) Merge Sort               O(nlogn)         |\n";
    std::cout << "|   8) Exit Application         O(1)             |\n";
    std::cout << "|   9) Redisplay Options        O(1)             |\n";
    std::cout << "|                                                |\n";
    std::cout << "==================================================\n";
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

int getChoice()
{
    int choice;
    std::cout << "---> ";
    std::cin >> choice;

    while (choice > 9 || choice < 1)
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    while (!std::cin.good())
    {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid, re-enter ---> ";
        std::cin >> choice;
    }

    return choice;
}
