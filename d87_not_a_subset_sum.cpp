/*
Given a array arr[] of positive integers, find the smallest positive integer such that it cannot be
represented as the sum of elements of any subset of the given array set.
*/
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        int n = arr.size();
        
        int tsum = 0;
        vector<int> vec;
        
        for(int i = 0; i < n; i++) {
            tsum += arr[i];
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += arr[j];
                vec.push_back(sum);
            }
        }
        
        sort(vec.begin(), vec.end());
        
        for(int i = 1; i <= tsum; i++) {
            if(find(vec.begin(), vec.end(), i) == vec.end())
                return i;
        }
        
        return tsum+1;
    }
};