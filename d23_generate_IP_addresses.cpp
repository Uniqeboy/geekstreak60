/*
Given a string s containing only digits, your task is to restore it by returning all possible
valid IP address combinations. You can return your answer in any order.
A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255(inclusive).
Note: The numbers cannot be 0 prefixed unless they are 0. For example, 1.1.2.11 and 0.11.21.1 are valid IP
Given a string s containing only digits, your task is to restore it by returning all possible valid IP address combinations. You can return your answer in any order.

A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255(inclusive).

Note: The numbers cannot be 0 prefixed unless they are 0. For example, 1.1.2.11 and 0.11.21.1 are valid IP addresses while 01.1.2.11 and 00.11.21.1 are not.
If there are no possible valid IP address return an empty list. The driver code will print -1 in this caseaddresses while 01.1.2.11 and 00.11.21.1 are not.
If there are no possible valid IP address return an empty list. The driver code will print -1 in this case
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isValid(const string &s) {
        if (s.size() > 1 && s[0] == '0')
            return false;

        int val = stoi(s);
        return val <= 255;
    }
    
    void generateIpRec(const string &s, int index, string curr, int cnt, vector<string> &res) {
    
        if (index >= s.size())
            return;
    
        if (cnt == 3) {
            string last = s.substr(index);
            if (last.size() <= 3 && isValid(last))
                res.push_back(curr + last);
            return;
        }
    
        string segment = "";
    
        for (int i = index; i < min(index + 3, (int)s.size()); i++) {
            segment += s[i];
    
            if (isValid(segment)) {
                generateIpRec(s, i + 1, curr + segment + ".", cnt + 1, res);
            }
        }
    }
    
    vector<string> generateIp(string s) {
        vector<string> res;
        generateIpRec(s, 0, "", 0, res);
        return res;
    }
};