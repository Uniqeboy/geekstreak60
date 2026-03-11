/*
Given an array arr[] of positive integers, find the total sum of the minimum 
elements of every possible subarrays.
Note: It is guaranteed that the total sum will fit within a 32-bit unsigned
integer.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
    
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
    
        while (!st.empty()) st.pop();
    
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
    
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += arr[i] * left[i] * right[i];
        }
    
        return result;
    }
};


class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int ans = 0;
        int n = arr.size();
        int mini = arr[0];
        for(int i = 0; i < n; i++) {
            ans += arr[i];
            int mini = arr[i];
            for(int j = i+1; j < n; j++) {
                if(mini > arr[j])
                    mini = arr[j];
                ans += mini;
            }
        }
        return ans;
    }
};