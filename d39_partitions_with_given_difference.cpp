/*
Given an array arr[] and an integer diff, count the number of ways to partition the array
into two subsets such that the difference between their sums is equal to diff.

Note: A partition in the array means dividing an array into two subsets say S1 and S2
such that the union of S1 and S2 is equal to the original array and each element is
present in only one of the subsets.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int solve(vector<int>& arr, int cs, int i, int& target, vector<vector<int>>& dp) {
        if(i >= arr.size())
            return (cs == target) ? 1 : 0;
            
        if(dp[i][cs] != -1)
            return dp[i][cs];
        
        int taken = solve(arr, cs, i+1, target, dp);
        
        int not_taken = 0;
        if(cs + arr[i] <= target)
            not_taken = solve(arr, cs+arr[i], i+1, target, dp);
            
            return dp[i][cs] = (taken + not_taken);
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        
        for (auto element : arr)
            sum += element;

        if ((sum + diff) % 2 != 0 || sum < diff)
            return 0;
        
        int target = (sum + diff) / 2;
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        
        return solve(arr, 0, 0, target, dp);
    }
};







class Solution {
  public:
    int solve(vector<int>& arr, int cs, int i, int& target) {
        if(i >= arr.size())
            return (cs == target) ? 1 : 0;
            
        int taken = solve(arr, cs, i+1, target);
        
        int not_taken = 0;
        if(cs + arr[i] <= target)
            not_taken = solve(arr, cs+arr[i], i+1, target);
            
            return taken + not_taken;
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        int ans = 0;
        int sum = 0;
        
        for (auto element : arr)
            sum += element;

        if ((sum + diff) % 2 != 0 || sum < diff)
            return 0;
        
        int target = (sum + diff) / 2;
        
        return solve(arr, 0, 0, target);
    }
};