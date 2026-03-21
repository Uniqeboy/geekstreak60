/*
You are given an integer array arr[] containing distinct elements.
Your task is to return an array where the ith element denotes the number of unique
BSTs formed when arr[i] is chosen as the root.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> factorial(int n) {
        vector<int> fact(n+1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++)
            fact[i] = fact[i-1]*i;
            
        return fact;
    }
    
    int getcatalon(int n, vector<int>& fact) {
        return fact[2*n]/(fact[n+1]*fact[n]);
    }
    
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> sorted;
        
        for(int i = 0; i < n; i++)
            sorted.push_back({arr[i], i});
            
        sort(sorted.begin(), sorted.end());
        
        vector<int> fact = factorial(2*n);
        
        vector<int> BSTcount(n);
        
        for(int i = 0; i < n; i++) {
            int j = sorted[i][1];
            BSTcount[j] = getcatalon(i, fact)*getcatalon(n-i-1, fact);
        }
        
        return BSTcount;
    }
};