/*
Given an array arr[] of integers, count the number of subarrays in arr[] which are strictly increasing with size
greater or equal to 2. A subarray is a contiguous part of array. A subarray is strictly increasing if each element 
is greater then it's previous element if it exists.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j - 1] >= arr[j]) {
                    break;
                }
                count++;
            }
        }

        return count;
    }
};


int countIncreasing(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            len++;
        } 
        else {
            count += (len * (len - 1)) / 2;
            len = 1;
        }
    }

    count += (len * (len - 1)) / 2;
    return count;
}
