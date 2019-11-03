#ifndef SORTS_H
#define SORTS_H
#include <iostream>

// SWAP (swaps to variables using reference)
// Pre: two distinct variables, same type: x,y
// Post: the variables x,y swapped
// Returns: x and y with values swapped
template <typename T>
void swap(T& lhs, T& rhs);

// BUBBLE SORT (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void bubble_sort(T *array, int size);

// BUBBLE SORT DEMO (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
// DEMOS EACH PASS FOR THE SORT
template <typename T>
void bubble_sort_demo(T *array, int size);

// SELECTION SORT (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void selection_sort(T *array, int size);

// SELECTION SORT DEMO (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
// DEMOS EACH PASS FOR THE SORT
template <typename T>
void selection_sort_demo(T *array, int size);

// INSERTION SORT (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void insertion_sort(T* array, int size);

// INSERTION SORT DEMO (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
// DEMOS EACH PASS FOR THE SORT
template <typename T>
void insertion_sort_demo(T* array, int size);

// DOUBLE ENDED SELECTION SORT (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void double_selection_sort(T *array, int size);

// DOUBLE ENDED SELECTION SORT DEMO (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
// DEMOS EACH PASS FOR THE SORT
template <typename T>
void double_selection_sort_demo(T *array, int size);

// EXCHANGE SORT (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void exchange_sort(T* array, int size);

// EXCHANGE SORT DEMO (sorts an array of type T in O(n^2))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
// DEMOS EACH PASS FOR THE SORT
template <typename T>
void exchange_sort_demo(T* array, int size);

// MERGE (merges an array)
// Pre: A non-empty array; left, mid, right indices
// Post: merges two subarrays
// Returns: nothing; void
template <typename T>
void merge(T* arr, int left, int mid, int right);

// MERGE SORT (sorts an array of type T in O(nlogn))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void merge_sort(T* array, int left, int right);

// HEAPIFY (makes a max heap)
// Pre: a non-empty array, and a node [index]
// Post: makes a max heap
// Returns: A binary heap (max) (by address given)
template <typename T>
void heapify(T* array, int size, int node);

// HEAP SORT (sorts an array of type T in O(nlogn))
// Pre: An array of type T, usually unsorted
// Post: Sorts an array in ascending order
// Returns: A sorted array (by address given)
template <typename T>
void heap_sort(T* array, int size);

#include "Sorts.cpp"
#endif
