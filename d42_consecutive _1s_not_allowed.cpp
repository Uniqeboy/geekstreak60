/*
Given a positive integer n, count all possible distinct binary strings of length n such that there are no consecutive 1’s.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(string s, int n, int wasone, vector<vector<int>>& dp) {
        if(s.size() == n)
            return 1;
           
        if(dp[s.size()][wasone] != -1)
            return dp[s.size()][wasone];
            
        int one = 0;
        int zero = 0;
        
        if(!wasone) {
            one = solve(s+'1', n, 1, dp); // 1
            zero += solve(s+'0', n, 0, dp); // 0
        }
        else {
            zero += solve(s+'0', n, 0, dp); // 0
        }
        
        return dp[s.size()][wasone] = (one + zero);
    }
    
    int countStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve("", n, 0, dp);
    }
};