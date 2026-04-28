/*
Given a string s of length n consisting of uppercase English letters and an integer k, you are allowed to
perform at most k operations.  In each operation, you can change any character of the string to any other
uppercase English letter.
Determine the length of the longest substring that can be transformed into a string with all identical
characters after performing at most k such operations.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestSubstr(string& s, int k) {
        int n = s.size();
        unordered_map<char, int> freq;    
        int maxFreq = 0;  
        int res = 0;
        
        int l = 0;   
        for (int r = 0; r < n; ++r) {
            freq[s[r]]++;
        
            maxFreq = max(maxFreq, freq[s[r]]);
            if (r - l + 1 - maxFreq > k) {
                freq[s[l]]--;  
                ++l;           
            }

            res = max(res, r - l + 1);
        }
        
        return res;
    }
};