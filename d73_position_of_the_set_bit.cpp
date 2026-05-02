/*
Given an integer n, determine position of the only set bit (1) in its binary representation.
The position is counted starting from 1 at the least significant bit (LSB).

If n contains exactly one set bit, return its position.
If n contains no set bits or more than one set bit, return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findPosition(int n) {
        bool nobit = false;
        int ans = -1;
        for(int i = 1; n > 0; n = n>>1, i++) {
            int bit = n & 1;
            if(bit) {
                ans = i;
                if(!nobit)
                    nobit = true;
                else
                    return -1;
            }
        }
        return ans;
    }
};