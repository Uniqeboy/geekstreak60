/*
Given two strings s1 and s2 consisting of only lowercase English letters and of equal length,
check if these two strings are isomorphic to each other.
If the characters in s1 can be changed to get s2, then two strings, s1 and s2 are isomorphic.
A character must be completely swapped out for another character while maintaining the order of
the characters. A character may map to itself, but no two characters may map to the same character.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        unordered_map<int, int> map1, map2;
        
        for(int i =0; i < s1.size(); i++) {
            if(map1.find(s1[i]) == map1.end())
                map1[s1[i]] = i;
            if(map2.find(s2[i]) == map2.end())
                map2[s2[i]] = i;
                
            if(map1[s1[i]] != map2[s2[i]])
                return false;
        }
        return true;
    }
};