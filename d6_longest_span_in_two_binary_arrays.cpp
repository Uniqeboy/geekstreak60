/*
Given two binary arrays, a1[] and a2[] of equal length. Find the length of longest
common span (i, j), where i<= j such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(2*n + 1, -1);
        int ps1 = 0;
        int ps2 = 0;
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ps1 += a1[i];
            ps2 += a2[i];
            
            int d = ps1 - ps2;
            int ind = d + n;
            
            if(d == 0) 
                ans = i+1;
            else if(diff[ind] != -1)
                ans = max(ans, i-diff[ind]);
            else
                diff[ind] = i;
        }
        
        return ans;
    }
};