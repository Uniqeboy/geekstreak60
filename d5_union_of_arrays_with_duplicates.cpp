#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        int i = 0, j = 0;
         
        int as = a.size(), bs = b.size();
        while(i < as || j < bs) {
            if(i < as)
                s.insert(a[i]);
            if(j < bs)
                s.insert(b[j]);
                
            i++, j++;
        }
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};