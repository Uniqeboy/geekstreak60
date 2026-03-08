/*
You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring that contains exactly k distinct characters.
Note : If no such substring exists, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int i = 0, j = 0;         
        int cnt = 0;               
        int maxi = -1;
        
        vector<int> fre(26, 0);  
        while (j < n) {
            fre[s[j] - 'a']++;
            if (fre[s[j] - 'a'] == 1) cnt++;
            while (cnt > k) {
                fre[s[i] - 'a']--;
                
                if (fre[s[i] - 'a'] == 0) cnt--;  
                i++;
            }
    
            if (cnt == k) {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
    
        return maxi;
    }
};