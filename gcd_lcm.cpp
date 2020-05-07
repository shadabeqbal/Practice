// GCD and LCM
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
    int a, b;
    cout << "Enter Numbers: ";
    cin >> a >> b;
    cout << "GCD: " << gcd(a, b);
    cout << "\nLCM: " << lcm(a, b);
}
