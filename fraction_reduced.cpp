// Product of given N fractions in reduced form
//https://www.geeksforgeeks.org/product-given-n-fractions-reduced-form/

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
void reduced_product(int n, int *a, int *b)
{
    int new_num = 1;
    int new_den = 1;
    for (int i = 0; i < n; i++)
    {
        new_num *= a[i];
        new_den *= b[i];
    }
    int g = gcd(new_num, new_den);
    new_num /= g;
    new_den /= g;

    cout << new_num << "/" << new_den;
}
int main()
{
    int n = 4;
    int num[] = {1, 2, 5,9};
    int den[] = {2, 1, 6,27};
    reduced_product(n, num, den);

    return 0;
}
