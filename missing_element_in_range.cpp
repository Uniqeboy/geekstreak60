/*
Given an array arr[] of integers and a range [low, high], find all the numbers within the range
that are not present in the array. return the missing numbers in sorted order.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> ans;
        map<int, bool> m;
        
        for(int it : arr) {
            if(it >= low && it <= high)
                m[it] = true;
        }

        for(int i = low; i <= high; i++) {
            if(!m[i])
                ans.push_back(i);
        }
        return ans;
    }
};