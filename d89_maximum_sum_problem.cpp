/*
Given a number n, find its maximum sum value with 3 recursive breaks described below.

Break into three parts n/2, n/3, and n/4 (consider only the integer part or floor value).
Each number obtained in this process can be divided further recursively. 
At every step,  we can take the max of current value of n or the max value obtained with recursive process.
It is possible that we don't divide the number at all and choose it as final answer.
*/
#include<iostream>
using namespace std;
class Solution {
  public:
    int solve(int n) {
        if(n == 1 || n == 0)
            return n;
            
        int ans = max(n, solve(n/2) + solve(n/3) + solve(n/4));
        return ans;
    }
    
    int maxSum(int n) {
        return solve(n);
    }
};