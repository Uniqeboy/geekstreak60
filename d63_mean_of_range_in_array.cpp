/*
Given an integer array arr[] and a 2D array queries[][]. Each query queries[i] = [l, r]
represents a subarray ranging from index l to r (inclusive). For every query, compute
the mean (average) of the elements in the specified range, and return the floor value of that mean.
Return an array where each element corresponds to the result of a query.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &q) {
        int n = arr.size();
        int m = q.size();
        
        vector<int> ans;
        vector<int> ps(n+1, 0);
        
        
        for(int i = 1; i <= n; i++)
            ps[i] = ps[i-1] + arr[i-1];
        
        for (int i = 0; i < m; i++) {
            int l = q[i][0];
            int r = q[i][1];
            
            int sum = ps[r + 1] - ps[l];
            int count = (r - l + 1);
    
            ans.push_back(sum / count);
        }
        
        return ans;
    }
};