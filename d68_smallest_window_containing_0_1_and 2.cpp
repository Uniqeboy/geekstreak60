/*
Given a string s consisting only of the characters '0', '1' and '2', determine the length
of the smallest substring that contains all three characters at least once.
If no such substring exists, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int smallestSubstring(string s) {
        int n = s.size();
        
        bool z = false, o = false, t = false;
        int zi = 0, oi = 0, ti = 0;
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                z = true;
                zi = i;
            }
            else if(s[i] == '1') {
                o = true;
                oi = i;
            }
            else if(s[i] == '2'){
                t = true;
                ti = i;
            }
        
            if(z && o && t) {
                ans = min(ans, max({zi, oi, ti}) - min({zi, oi, ti}));
            }
        }
        
        if(ans == INT_MAX)
            return -1;
        else
            return ans+1;
    }
};
