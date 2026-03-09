/*
Given a string s, return the lexicographically largest string that can be obtained by
swapping at most one pair of characters in s.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string largestSwap(string &s) {
        char maxd = '0';
        int maxi = -1;
        int l = -1, r = -1;
        
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] > maxd) {
                maxd = s[i];
                maxi = i;
            }
            else if(s[i] < maxd) {
                l = i;
                r = maxi;
            }
        }
        
        if(l == -1)
            return s;
            
         swap(s[l], s[r]);
         return s;
    }
};