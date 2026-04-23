/*
Given an array of integers arr[], return true if it is possible to split it in two subarrays
(without reordering the elements), such that the sum of the two subarrays are equal. If it is
not possible then return false.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        for(int it : arr)
            sum += it;

        int cs = 0;
        for(int it : arr) {
            cs += it;
            if(2*cs == sum) 
                return true;
        }
        return false;
    }
};
