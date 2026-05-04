/*
Given an integer n, determine whether its binary representation forms a palindrome.
Return true if the binary representation of n is a palindrome; otherwise, return false.
Note: A binary representation is considered a palindrome if it reads the same forward and backward.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        if(n % 2 == 0)
            return false;
            
        vector<int> bin;
        while(n) {
            bin.push_back(n & 1);
            n = n >> 1;
        }
        
        int i = 0, j = bin.size()-1;
        while(i <= j) {
            if(bin[i++] != bin[j--])
                return false;
        }
        
        return true;
    }
};