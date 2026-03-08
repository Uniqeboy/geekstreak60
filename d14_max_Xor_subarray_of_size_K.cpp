/*
Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.
Note: A subarray is a contiguous part of any given array.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] ^ arr[i];
        }
    
        int maxXor = 0;
        for (int i = 0; i <= n - k; i++) {
            
            int currXor = prefix[i + k] ^ prefix[i];
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};