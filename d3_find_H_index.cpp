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