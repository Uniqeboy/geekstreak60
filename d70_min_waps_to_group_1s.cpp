/*
You are given a binary array arr[] consisting only of 0s and 1s. Determine the minimum number of swaps
required to group all the 1s together in a contiguous subarray.
A swap operation allows you to choose any two indices i and j and exchange their values (i.e., swap(arr[i], arr[j])).
If the array contains no 1s, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        int numberOfOnes = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1)
                numberOfOnes++;
        }
        
        if (numberOfOnes == 0)
            return -1;
            
        int x = numberOfOnes;
    
        int count_ones = 0, maxOnes;
        for (int i = 0; i < x; i++) {
            if (arr[i] == 1)
                count_ones++;
        }
    
        maxOnes = count_ones;
        for (int i = 1; i <= n - x; i++) {
    
            if (arr[i - 1] == 1)
                count_ones--;
    
            if (arr[i + x - 1] == 1)
                count_ones++;
    
            if (maxOnes < count_ones)
                maxOnes = count_ones;
        }
    
        int numberOfZeroes = x - maxOnes;
    
        return numberOfZeroes;
    }
};