// Justin Ventura COSC220-003
// LAB9: lab9aux.cpp

#include "lab9aux.h"
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
void removeDup(std::vector<T> & v)
{
    if (v.begin() == v.end())
    return;

    int N = v.size();
    int i, j;
    int nextIndex = 1;
    int deleted = 0;
    bool isDup = false;

    for (i = 1; i < N; i++) // loops through vect once
    {
        isDup = false;
        for (j = 0; j < i; j++)
        {
            if (v[j] == v[i])
            {
                isDup = true;
            }
        }
        if (isDup == false)
        {
            v[nextIndex] = v[i];
            nextIndex++;
        }
        else deleted++;
    }
    v.resize(N - deleted);
    std::sort(v.begin(), v.end());
}

template <typename T>
void removeDup2(std::vector<T> & v)
{
    if (v.begin() == v.end())
    return;

    int i, j, temp;
    int N = v.size();
    int nextIndex = 1, deleted = 0;
    bool isDup = false;

    for (i = 1; i < N; i++)
    {
        isDup = false;
        temp = seqVectSearch(v, 0, i, v[i]);
        if (v[temp] == v[i]) isDup = true;

        if (isDup == false)
        {
            v[nextIndex] = v[i];
            nextIndex++;
        }
        else deleted++;
    }
    v.resize(N - deleted);
    std::sort(v.begin(), v.end());
}


template <typename T>
void removeDup3(std::vector<T> & v)
{
    if (v.begin() == v.end())
    return;

    std::sort(v.begin(), v.end());
    std::vector<T> nonDups;  // this will store the non-duplicates

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] != v[i - 1])
        {
            nonDups.push_back(v[i]);
        }
    }
    v = nonDups;
}

template <typename T>
unsigned seqVectSearch(const std::vector<T> & v, unsigned first,
    unsigned last, const T& target)
    {
        int i;
        for (i = first; i < last; i++)
        {
            if (v[i] == target) return i;
        }
        return -1;
    }

template <typename T>
void writeVector(const std::vector<T> & v)
{
    unsigned i;
    unsigned n = v.size();

    for (i = 0; i < n; i++)
    std::cout << v[i] << ' ';
    std::cout << std::endl;
}
