// Chef and Street Food
//https://www.codechef.com/LRNDSA02/problems/STFOOD
//Author: Shadab Eqbal

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <iterator>
#include <climits>
#include <math.h>

using namespace std;

int main()
{
    int t, n, x, val = 0, best = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        vector<int> V(n);
        vector<int> P(n);
        vector<int> S(n);
        for (int j = 0; j < n; j++)
        {
            cin >> S[j];
            cin >> P[j];
            cin >> V[j];

            x = P[j] / (S[j] + 1);
            val = x * V[j];
            best = max(val, best);
        }

        cout << best << "\n";
        best = 0;
        val = 0;
    }
}
