/* 
Given an array of integers arr[] and a number k, count the number of subarrays having
XOR of their elements as k.
Note: It is guranteed that the total count will fit within a 32-bit integer.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> pre_xor;
        long ans = 0;
        int xoc = 0;
        
        for(int it : arr) {
            xoc ^= it;
            if(xoc == k)
                ans++;
                
            if(pre_xor.find(xoc^k) != pre_xor.end())
                ans += pre_xor[xoc^k];
                
            pre_xor[xoc]++;
            
        }
        return ans;
    }
};
