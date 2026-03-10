/*
You are given an integer array arr[ ]. Your task is to count the number of subarrays where
the first element is the minimum element of that subarray.
Note: A subarray is valid if its first element is not greater than any other element in that subarray.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSubarrays(vector<int>& arr){
        stack<int> st;
        int ans = 0;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
                
            int last = (st.empty() ? n : st.top());
            ans += (last - i);
            st.push(i);
        }
        return ans;
    }
};