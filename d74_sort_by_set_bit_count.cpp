/*
Given an array arr[] of integers, sort the array (in descending order) according to count of
set bits in binary representation of array elements. 
Note: For integers having same number of set bits in their binary representation, sort according
to their position in the original array i.e., a stable sort.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countbits(int num) {
        int ans = 0;
        for(; num; num = num >> 1) {
            int bit = num & 1;
            if(bit)
                ans++;
        }
        return ans;
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        vector<pair<pair<int, int>, int>> temp;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int bits = countbits(arr[i]);
            temp.push_back({{bits, i}, arr[i]});
        }
        
        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
            if(a.first.first == b.first.first)
                return a.first.second < b.first.second;
            return a.first.first > b.first.first;
        });
        
        vector<int> ans;
        for(auto it : temp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};