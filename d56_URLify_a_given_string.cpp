/*
Given a string s, replace all the spaces in the string with '%20'.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string URLify(string &s) {
        string result = "";

        for(char c : s) {
            if(c == ' ')
                result += "%20";
            else
                result += c;
        }

        return result;
    }
};