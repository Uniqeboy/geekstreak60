/*
Given two strings s and p. Find the smallest substring in s consisting of all the
characters (including duplicates) of the string p. Return empty string in case no
such substring is present.
If there are multiple such substring of the same length found, return the one with the
least starting index.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isValid(string &s, string &p, int mid, int &start){
        int count[26] = {0};
        
        int distinct = 0;
        for (char x : p){
            if (count[x-'a'] == 0)
                distinct++;
            count[x-'a']++;
        }

        int curr_count = 0;
        for (int i = 0; i < s.size(); i++){
            count[s[i]-'a']--;
            if (count[s[i]-'a'] == 0){
                curr_count++;
            }
    
            if (i >= mid){
                count[s[i - mid]-'a']++;
                if (count[s[i - mid]-'a'] == 1){
                    curr_count--;
                }
            }
    
            if (i >= mid - 1){
                if (curr_count == distinct){
                    start = (i - mid) + 1;
                    return true;
                }
            }
        }
    
        return false;
    }
    string minWindow(string s, string p){
        int m = s.length();
        int n = p.length();
    
        if (m < n)
            return "";
    
        int minLength = INT_MAX;
        int low = n, high = m;
        int idx = -1;
    
        while (low <= high){
            int mid = (low + high) / 2;
            int start;
    
            if (isValid(s, p, mid, start)){
                if (mid < minLength){
                    minLength = mid;
                    idx = start;
                }
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    
        if (idx == -1)
            return "";
    
        return s.substr(idx, minLength);
    }
};