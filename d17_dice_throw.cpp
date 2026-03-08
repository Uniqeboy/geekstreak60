/*
Given n dice each with m faces. Find the number of ways to get sum x which is the
summation of values on each face when all the dice are thrown.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(int dices, int faces, int target) {
        vector<int> prev(target+1, 0);
        vector<int> cur(target+1, 0);
        prev[0] = 1;
        
        for(int d = 1; d <= dices; d++) {
            for(int t = 1; t <= target; t++) {
                int ans = 0;
                for(int i = 1; i <= faces; i++) {
                    if(t-i >= 0)
                        ans += prev[t-i];
                }
                cur[t] = ans;
            }
            prev = cur;
        }
        return prev[target];
    }
    int noOfWays(int m, int n, int x) {
        return solve(n , m, x);
    }
};