//Quick Sort
//Author: Shadab Eqbal

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <iterator>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void q_sort(vector<int> &arr, int i, int j)
{
    if (i < j)
    {
        int q = partition(arr, i, j);
        q_sort(arr, i, q - 1);
        q_sort(arr, q + 1, j);
    }
}

int main()
{
    vector<int> vec = {3, 1, 2, 9, 7, 5, 6, 8, 4};
    q_sort(vec, 0, vec.size() - 1);
    for (int i : vec)
        cout << i << " ";
}
