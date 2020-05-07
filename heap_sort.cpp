//Quick Sort
//Author: Shadab Eqbal

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <iterator>
#include <climits>
#include <math.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void max_heapify(int *arr, int i, int size)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < size && arr[l] > arr[largest])
        largest = l;

    if (r < size && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size);
    }
}
void heapSort(int *arr, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        max_heapify(arr, i, 0);
    }
}
int main()
{
    int vec[] = {3, 1, 2, 9, 7, 5, 6, 8, 4};
    heapSort(vec, 8);
    for (int i = 0; i < 9; i++)
        cout << vec[i] << " ";
}
