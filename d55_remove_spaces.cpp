/*
Given a string s, remove all the spaces from the string and return the modified string.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string removeSpaces(string& s) {
        int i = 0, j = 0;
        while(j < s.size()) {
            if(s[j] != ' ') {
                s[i++] = s[j];
            }
            j++;
        }
        s.erase(s.begin() + i, s.end());
        return s;
    }
};