// lcm and gcd of array
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
int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int arr[] = {2, 7, 3, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = arr[0];
    int y = arr[0];
    for (int i = 1; i < size; i++)
    {
        x = lcm(x, arr[i]);
        y = gcd(y, arr[i]);
    }

    cout << "LCM: " << x << "\nGCD: " << y;
}
