/*
Given a string s, determine whether its characters can be rearranged to form a palindrome.
Return true if it is possible to rearrange the string into a palindrome; otherwise, return false.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool canFormPalindrome(string &s) {
        map<char, int> m;
        for(char ch : s)
            m[ch]++;
            
        int odd = 0;
        for(auto it : m)
            if(it.second % 2)
                odd++;
        return odd <= 1;
    }
};