/*
Given an array arr[], determine whether it represents the level-order traversal of a valid max heap.
Return true if it does; otherwise, return false.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool solve(vector<int> &arr, int root) {
        int n = arr.size();
        
        int li = 2*root+1;
        int ri = 2*root+2;
        
        bool left = true;
        bool right = true;
        
        if(li < n) {
            left = solve(arr, li);
            left = left && arr[root] >= arr[li];
        }
        
        if(ri < n) {
            right = solve(arr, ri);
            right = right && arr[root] >= arr[ri];
        }
        return (left && right );
    }
    
    bool isMaxHeap(vector<int> &arr) {
        return solve(arr, 0);
    }
};
