//Counting Elements (leetcode.com)
//30 days of code

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countElements(vector<int>& arr) {
    int count = 0, i = 0;
    sort(arr.begin(),arr.end());
    for(int x = 1;x<arr.size();x++){
        if(arr[i] == arr[x]-1){
            i++;
            count++;
        }
        if((arr[x] - arr[x-1]) > 1)
            i=x;
        
    }        
    return count;
}

int main()
{
   vector<int> vec = {1,1,2}; //op-2
   cout<<countElements(vec);
}