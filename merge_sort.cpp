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

void merge(int *arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[mid + j + 1];

    i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int i, int j)
{
    if (i < j)
    {
        int mid = i + (j - i) / 2;
        merge_sort(arr, i, mid);
        merge_sort(arr, mid + 1, j);
        merge(arr, i, mid, j);
    }
}

int main()
{
    int vec[] = {3, 1, 2, 9, 7, 5, 6, 8, 4};
    merge_sort(vec, 0, 8);
    for (int i = 0; i < 9; i++)
        cout << vec[i] << " ";
}
