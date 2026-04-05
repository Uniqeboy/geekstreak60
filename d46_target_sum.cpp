/*
Given an array of integers arr[] and an integer target. We need to build an expression out of arr[]
by adding one of the symbols '+' or  '-' before each integer in arr[] and then concatenate all the integers. 
For example : if arr[] = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them
to build the expression "+2-1".
Return the number of different expressions that can be built, which evaluates to target.

Note : An expression is considered different from another if the placement of '+' and '-' operators
differs, even if the resulting value is the same. 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findPossibleWays(vector<int>& arr, vector<vector<int> >& dp, int i, int s, int &target, int &total_sum) {
    if (s == target && i == arr.size())
        return 1;

    if (i >= arr.size())
        return 0;

    if (dp[i][s + total_sum] != -1)
        return dp[i][s + total_sum];

    return dp[i][s + total_sum] = findPossibleWays(arr, dp, i + 1, s + arr[i], target, total_sum) +
                                  findPossibleWays(arr, dp, i + 1, s - arr[i], target, total_sum);
}
    int totalWays(vector<int>& arr, int target) {
        int n = arr.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += arr[i];
        }
        vector<vector<int>> dp(n , vector<int>(2*totalSum + 1, -1));
        return findPossibleWays(arr , dp , 0 , 0 , target , totalSum);
    }
};