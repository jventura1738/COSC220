#include "Sorts.h"

template <typename T>
void swap(T& lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

template <typename T>
void bubble_sort(T *array, int size)
{
    bool swapped = false;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
}

template <typename T>
void bubble_sort_demo(T *array, int size)
{
    bool swapped = false;
    std::cout << "\nIntermediate Sequences\n";
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        for (int k = 0; k < size; k++)
        {
            std::cout << array[k] << " ";
        }
        std::cout << "\n";
        if (swapped == false) break;
    }
}

template <typename T>
void selection_sort(T *array, int size)
{
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index]) min_index = j;
        }
        swap(array[min_index], array[i]);
    }
}

template <typename T>
void selection_sort_demo(T *array, int size)
{
    int i, j, min_index;
    std::cout << "\nIntermediate Sequences\n";
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index]) min_index = j;
        }
        swap(array[min_index], array[i]);
        for (int k = 0; k < size; k++)
        {
            std::cout << array[k] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void insertion_sort(T* array, int size)
{
    int i, j, sel;
    for (i = 1; i < size; i++)
    {
        sel = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > sel)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = sel;
    }
}

template <typename T>
void insertion_sort_demo(T* array, int size)
{
    int i, j, sel;
    std::cout << "\nIntermediate Sequences\n";
    for (i = 1; i < size; i++)
    {
        sel = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > sel)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = sel;
        for (int k = 0; k < size; k++)
        {
            std::cout << array[k] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void double_selection_sort(T *array, int size)
{
    int i, j, k, min_index, max_index, min, max;
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        min_index = i, max_index = i;
        min = array[i], max = array[i];
        for (k = i; k <= j; k++)
        {
            if (array[k] > max)
            {
                max = array[k];
                max_index = k;
            }
            else if (array[k] < min)
            {
                min = array[k];
                min_index = k;
            }
        }
        swap(array[i], array[min_index]);
        if (array[min_index] == max) swap(array[j], array[min_index]);
        else swap(array[j], array[max_index]);
    }
}

template <typename T>
void double_selection_sort_demo(T *array, int size)
{
    int i, j, k, min_index, max_index, min, max;
    std::cout << "\nIntermediate Sequences\n";
    for (i = 0, j = size - 1; i < j; i++, j--)
    {
        min_index = i, max_index = i;
        min = array[i], max = array[i];
        for (k = i; k <= j; k++)
        {
            if (array[k] > max)
            {
                max = array[k];
                max_index = k;
            }
            else if (array[k] < min)
            {
                min = array[k];
                min_index = k;
            }
        }
        swap(array[i], array[min_index]);

        if (array[min_index] == max) swap(array[j], array[min_index]);
        else swap(array[j], array[max_index]);
        for (int k = 0; k < size; k++)
        {
            std::cout << array[k] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
void exchange_sort(T* array, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            swap(array[i], array[j]);
        }
    }
}

template <typename T>
void exchange_sort_demo(T* array, int size)
{
    int i, j;
    std::cout << "\nIntermediate Sequences\n";
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            swap(array[i], array[j]);
        }
        for (int k = 0; k < size; k++)
        {
            std::cout << array[k] << " ";
        }
        std::cout << "\n";
    }
}

void merge(int *array, int left, int mid, int right)
{
   int i, j, k, sub1, sub2;
   //size of left and right sub-arrays
   sub1 = mid - left + 1; sub2 = right - mid;
   int subArr1[sub1], subArr2[sub2];
   //fill left and right sub-arrays
   for(i = 0; i < sub1; i++) subArr1[i] = array[left + i];
   for(j = 0; j < sub2; j++) subArr2[j] = array[mid + 1 + j];
   i = 0; j = 0; k = left;
   //merge temp arrays to real array
   while(i < sub1 && j < sub2)
   {
      if(subArr1[i] <= subArr2[j])
      {
         array[k] = subArr1[i];
         i++;
      }
      else
      {
         array[k] = subArr2[j];
         j++;
      }
      k++;
   }
   while(i < sub1) //extra element in left array
   {
      array[k] = subArr1[i];
      i++; k++;
   }
   while(j < sub2) //extra element in right array
   {
      array[k] = subArr2[j];
      j++;
      k++;
   }
}

template <typename T>
void merge_sort(T *array, int start, int end) {
   int mid;
   if(start < end)
   {
      mid = start + (end - start) / 2;
      // Sort first and second arrays
      merge_sort(array, start, mid);
      merge_sort(array, mid + 1, end);
      merge(array, start, mid, end);
   }
}

template <typename T>
void heapify(T* array, int size, int node)
{
    int max = node; // node is essentially i
    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < size && array[left] > array[max]) max = left;
    if (right < size && array[right] > array[max]) max = right;

    if (max != node)
    {
        swap(array[node], array[max]);
        heapify(array, size, max);
    }
}


template <typename T>
void heap_sort(T* array, int size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--) heapify(array, size, i);

    for (i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
