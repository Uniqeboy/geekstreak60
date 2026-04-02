/*
Given a fence with n posts and k colours, find out the number of ways of painting the fence so that not more
than two consecutive posts have the same colours.
Answers are guaranteed to be fit into a 32 bit integer.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countWays(int n, int k) {
        if(n == 1) return k;

        long long same = 0;
        long long diff = k;

        for(int i = 2; i <= n; i++) {
            long long newSame = diff;
            long long newDiff = (same + diff) * (k - 1);

            same = newSame;
            diff = newDiff;
        }

        return same + diff;
    }
};






class Solution {
  public:
    int solve(int n, int k, int one, int two,
                vector<vector<vector<int>>>& dp) {
        if(n == 0)
            return 1;
            
        if(dp[n][one+1][two+1] != -1)
            return dp[n][one+1][two+1];
            
        int ans = 0;
        for(int i = 0; i < k; i++) {
            if(one == two && one == i)
                continue;
                
            ans += solve(n-1, k, i, one, dp);
        }
        
        return dp[n][one+1][two+1] = ans;
    }
    
    int countWays(int n, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(k+1, -1)));
        return solve(n, k, -1, -1, dp);
    }
};