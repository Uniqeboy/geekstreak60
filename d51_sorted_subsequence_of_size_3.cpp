/*
Given an array arr[], find any subsequence of three elements such that, arr[i] < arr[j] < arr[k]
and (i < j < k).
If such a subsequence exists, return the three elements as an array. Otherwise, return an empty array.
Note:
The driver code will print 1 if the returned subsequence is valid and present in the array.
The driver code will print 0 if no such subsequence exists.
If the returned subsequence does not satisfy the required format or conditions, the output will be -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
    
        vector<int> smaller(n, -1);
        int min = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[min])
                min = i;
            else
                smaller[i] = min;
        }
    
        vector<int> greater(n, -1);
        int max = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[max])
                max = i;
            else
                greater[i] = max;
        }
    
        for (int i = 0; i < n; i++) {
            if (smaller[i] != -1 && greater[i] != -1)
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
        }
    
        return {};
    }
};