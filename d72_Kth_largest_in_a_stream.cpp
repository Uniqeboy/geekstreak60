/*
Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element)
after insertion of each element in the stream and if the Kth largest element doesn't exist, the answer
will be -1 for that insertion.
Return a list of size n, where each element represents the Kth largest value after the corresponding insertion.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> que;
        
        for(int i = 0; i < n; i++) {
            que.push(arr[i]);
            
            if(i < k-1) {
                ans.push_back(-1);
            }
            else {
                if(que.size() > k)
                    que.pop();

                ans.push_back(que.top());
            }
        }
        
        return ans;
    }
};