/*
Given an array arr[] consisting of 0’s and 1’s. A flip operation involves changing all
0's to 1's and all 1's to 0's within a contiguous subarray. Formally, select a range
(l, r) in the array arr[], such that (0 ≤ l ≤ r < n) holds and flip the elements in this range.
Return the maximum number of 1's you can get in the array after doing at most 1 flip operation.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxSumSub(vector<int> &arr) {
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            sum += arr[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        
        return ans;
    }
    
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int oneCnt = 0;
        
        for (int i=0; i<n; i++) {
            if (arr[i] == 1) {
                arr[i] = -1;
                oneCnt++;
            }
            else arr[i] = 1;
        }
        
        int maxDiff = maxSumSub(arr);
        return oneCnt + maxDiff;
    }
};