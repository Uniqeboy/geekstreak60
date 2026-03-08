/*
You are given an array citations[], where each element citations[i] represents the
number of citations received by the ith paper of a researcher. You have to calculate
the researcher’s H-index.
The H-index is defined as the maximum value H, such that the researcher has published at
least H papers, and all those papers have citation value greater than or equal to H.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int hIndex(vector<int>& ca) {
        sort(ca.begin(), ca.end());
        
        int ans = 0, n = ca.size();
        for(int i = n-1; i>=0; i--) {
            if(ca[i] >= n-i)
                ans++;
            else
                break;
        }
        return ans;
    }
};