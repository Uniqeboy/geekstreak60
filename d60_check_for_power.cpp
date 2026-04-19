/*
Given two positive integers x and y, determine if y is a power of x.
If y is a power of x, return true. Otherwise, return false.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPower(int x, int y) {
        float power = log(y)/log(x);
         
        if(power == (int)power)
            return true;
        else
            return false;
    }
};