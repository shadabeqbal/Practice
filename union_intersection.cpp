// Union and Intersection
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

void printIntersection(vector<int> &v1, vector<int> &v2)
{
    int s1 = v1.size();
    int s2 = v2.size();
    int i = 0, j = 0;
    vector<int> v3;
    while (i < s1 && j < s2)
    {
        if (v1[i] < v2[j])
        {
            i++;
        }
        else if (v1[i] > v2[j])
        {
            j++;
        }
        else if (v1[i] == v2[j])
        {
            v3.push_back(v1[i]);
            i++;
            j++;
        }
    }

    for (auto x : v3)
        cout << x << " ";
}
void printUnion(vector<int> &v1, vector<int> &v2)
{
    int s1 = v1.size();
    int s2 = v2.size();
    int i = 0, j = 0;
    vector<int> v3;
    while (i < s1 && j < s2)
    {
        if (v1[i] < v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
        else if (v1[i] == v2[j])
        {
            v3.push_back(v1[i]);
            i++;
            j++;
        }
    }
    while (i < s1)
    {
        v3.push_back(v1[i]);
        i++;
    }
    while (j < s2)
    {
        v3.push_back(v2[j]);
        j++;
    }
    for (auto i : v3)
        cout << i << " ";
}
int main()
{
    vector<int> v1 = {1, 2, 3, 7, 9, 11};
    vector<int> v2 = {2, 3, 5, 6, 7, 9};
    cout << "Union of V1 & V2: ";
    printUnion(v1, v2);
    cout << "\nIntersection of V1 & V2: ";
    printIntersection(v1, v2);
}
