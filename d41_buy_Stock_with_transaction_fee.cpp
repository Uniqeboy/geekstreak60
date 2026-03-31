/*
You are given an array arr[], in which arr[i] is the price of a given stock on the ith day and an integer k
represents a transaction fee. Find the maximum profit you can achieve. You may complete as many transactions
as you like, but you need to pay the transaction fee for each transaction.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxProfitRec(vector<int> &arr, int ind, 
              int buy, int k, vector<vector<int>> &memo) {

        int n = arr.size();
    
        if (ind == n) 
            return 0;
    
        if (memo[ind][buy] != -1)
            return memo[ind][buy];
            
        int profit;

        if (buy == 0) { 
            profit = max(maxProfitRec(arr, ind + 1, 0, k, memo), 
                     maxProfitRec(arr, ind + 1, 1, k, memo) - arr[ind]);
        }

        if (buy == 1) { 
            profit = max(maxProfitRec(arr, ind + 1, 1, k, memo), 
                arr[ind] - k + maxProfitRec(arr, ind + 1, 0, k, memo));
        }
        return memo[ind][buy] = profit;
    }
    
    int maxProfit(vector<int>& arr, int k) {
        int n = arr.size();
    
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return maxProfitRec(arr, 0, 0, k, memo);        
    }
};