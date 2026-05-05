/*
Given an integer array arr[] of size n, compute the sum of the bitwise XOR for all distinct pairs of elements.
That is, consider every pair of indices (i, j) such that 0 ≤ i < j < n, and calculate the total sum of
(arr[i] XOR arr[j]) over all such pairs.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        long sum = 0;
    
        for (int i = 0; i < 32; i++) {
            int oc = 0, zc = 0;
            for (int j = 0; j < arr.size(); j++)
                if((arr[j] >> i) & 1)
                    oc++;
                else
                    zc++;
                    
            sum += (long)oc*zc*(1 << i);
        }
    
        return sum;
    }
};