#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> m;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k) 
                sum--;
            else
                sum++;
                
            if(sum > 0)
                ans = i + 1;
            else
                if(m.find(sum-1) != m.end())
                    ans = max(ans, i - m[sum - 1]);
            
            if(m.find(sum) == m.end())
                m[sum] = i;
        }
        return ans;
    }
};