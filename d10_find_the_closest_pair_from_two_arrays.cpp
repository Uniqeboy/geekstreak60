/*
Given two sorted arrays arr1[] and arr2[] of size n and m and a number x, find the pair
whose sum is closest to x and the pair has an element from each array. In the case of multiple
closest pairs return any one of them.
Note : In the driver code, the absolute difference between the sum of the closest
pair and x is printed
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int diff = INT_MAX;
        int i = 0;
        int j = arr2.size()-1;
        int e1 = 0, e2 = 0;
        while(i < arr1.size() && j >= 0) {
            if(abs(arr1[i] + arr2[j] - x) < diff) {
                diff = abs(arr1[i] + arr2[j] - x);
                e1 = arr1[i], e2 = arr2[j];
            }
            
            if(arr1[i] + arr2[j] > x)
                j--;
            else
                i++;
        }
        return {e1, e2};
    }
};