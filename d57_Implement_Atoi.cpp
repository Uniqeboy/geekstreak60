/*
Given a string s, convert it into a 32-bit signed integer (similar to the atoi() function) without using any built-in conversion functions.
The conversion follows these rules:

Ignore Leading Whitespaces: Skip all leading whitespace characters.
Check Sign: If the next character is either '+' or '-', take it as the sign of the number. If no sign is present, assume the number is positive.
    Read Digits: Read the digits and ignore any leading zeros. Stop reading when a non-digit character is encountered or the end of the string is reached. If no digits are found, return 0.
    Handle Overflow: If the number exceeds the range of a 32-bit signed integer:
    Return 2³¹ − 1 (i.e., 2147483647) if it is greater than the maximum value.
    Return −2³¹ (i.e., -2147483648) if it is smaller than the minimum value.
Return the final integer value.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.size();
        
        while(i < n && s[i] == ' ')
            i++;
          
        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        if(i >= n)
            return 0;
            
        while(i < n && s[i] == '0')
            i++;
            
        if(i >= n)
            return 0;
        
        long long int ans = 0;
        while(i < n && isdigit(s[i])) {
             ans = ans*10 + (s[i] - '0');
             i++;
        }
              
        ans *= sign;
        if(ans > INT_MAX)
            return INT_MAX;
        
        if(ans < INT_MIN)
            return INT_MIN;
            
        return ans;
    }
};

