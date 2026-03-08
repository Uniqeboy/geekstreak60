/*
Given an array arr[] consisting of positive integers, your task is to find the
length of the longest subarray that contains at most two distinct integers.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int totalElements(vector<int>& arr) {
    
        map<int, int> mp;  
        int i = 0, j = 0, n = arr.size();
        int size = 0;
    
        while (j < n) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;  
            }
            size = max(size, j - i + 1);
            j++;  
        }
    
        return size;
    }
};