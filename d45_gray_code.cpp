/*
Given a number n, generate bit patterns from 0 to 2n-1 such that successive patterns differ by one bit. 
A Gray code sequence must begin with 0.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<string> graycode(int n) {
        if(n == 1)
            return {"0", "1"};
            
        vector<string> prev = graycode(n-1);
        vector<string> ans;
        
        for(auto s : prev) {
            ans.push_back("0" + s);
        }
        
        for(int i = prev.size()-1; i >= 0; i--) {
            ans.push_back("1" + prev[i]);
        }
        
        return ans;
    }
};