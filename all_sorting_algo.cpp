#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}

void selection_sort(vector<int> &vec)
{
    int n = vec.size();
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (vec[min] > vec[j])
            {
                min = j;
            }
        }

        swap(vec[i], vec[min]);
    }
}
void binary_search(vector<int> &vec, int i, int j, int s)
{
    if (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (s == vec[mid])
        {
            cout << "Element found at location " << mid << "\n";
            return;
        }
        if (s > vec[mid])
        {
            return binary_search(vec, mid + 1, j, s);
        }
        if (s < vec[mid])
        {
            return binary_search(vec, i, mid - 1, s);
        }
    }
}
void linear_search(vector<int> &vec, int i, int j, int k)
{
    if (i <= j)
    {
        if (vec[i] == k)
        {
            cout << "Element found at location " << i;
            return;
        }
        return linear_search(vec, i + 1, j, k);
    }
}
void insertion_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
                swap(vec[i], vec[j]);
        }
    }
}
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick_sort(vector<int> &vec, int i, int j)
{
    if (i < j)
    {
        int q = partition(vec, i, j);
        quick_sort(vec, i, q - 1);
        quick_sort(vec, q + 1, j);
    }
}
void merge(vector<int>&arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    
    i = 0; 
    j = 0;  
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void merge_sort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        merge_sort(vec, 0, mid);
        merge_sort(vec, mid + 1, high);
        merge(vec, low, mid, high);
    }
}
void heapify(vector<int>&vec,int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && vec[left] > vec[largest])
        largest = left;
    
    if(right<n && vec[right]>vec[largest])
        largest = right;
    
    if(largest != i){
        swap(vec[i],vec[largest]);
        heapify(vec,n,largest);
    }

}
void heap_sort(vector<int>&vec,int n){
    for(int i=n/2-1;i>=0;i--)
        heapify(vec,n,i);
    
    for(int i=n-1;i>0;i--){
        swap(vec[0],vec[i]);
        heapify(vec,i,0);
    }
}
int main()
{
    vector<int> vec = {33, 1, 8, 6, 2, 4};
    //bubble_sort(vec);
    //selection_sort(vec);
    //insertion_sort(vec);
    //quick_sort(vec, 0, vec.size());
    //merge_sort(vec, 0, vec.size());
    heap_sort(vec,vec.size());
    for (int i : vec)
        cout << i << " ";
    // //binary_search(vec, 0, vec.size(), 6);
    //linear_search(vec, 0,vec.size(),6);
}