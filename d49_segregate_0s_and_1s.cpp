/*
Given an array arr[] consisting of only 0's and 1's. Modify the array in-place to segregate
0s onto the left side and 1s onto the right side of the array.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0)
                arr[k++] = 0;
        }
        
        while(k < n)
            arr[k++] = 1;
    }
};