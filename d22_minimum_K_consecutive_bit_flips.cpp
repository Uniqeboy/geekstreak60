/*
You are given a binary array arr[] (containing only 0's and 1's) and an integer k.
In one operation, you can select a contiguous subarray of length k and flip all
its bits (i.e., change every 0 to 1 and every 1 to 0).
Your task is to find the minimum number of such operations required to make the entire
array consist of only 1's. If it is not possible, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kBitFlips(vector<int> &arr, int k) {
        int n = arr.size(); 
        int res = 0, flag = 0;
        vector<int> flipped(n + 1, 0); 
    
        for (int i = 0; i < n; i++) {
            flag = (flag ^ flipped[i]);
            
            if(flag == 1)
                arr[i] ^= 1;
            
            if(arr[i] == 0) {
                
                if(i + k > n) 
                    return -1;
                
                res += 1;
    
                flag ^= 1;
                flipped[i + k] = 1;
            }
        }
    
        return res; 
    }
};