/*
Given an array arr[] , return the final array by repeatedly apply the following operation from
left to right until no more valid operations can be performed.
If two adjacent elements have opposite signs:
If their absolute values are different, remove both elements and insert the one with the greater
absolute value, preserving its sign.
If their absolute values are equal, remove both elements without inserting any new element.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> s;
        
        for (int element : arr) {
            while (!s.empty() && s.back() * element < 0) {
                int top = s.back();
                
                if (abs(top) > abs(element)) {
                    element = top;
                    s.pop_back();
                }
                else if (abs(top) < abs(element)) {
                    s.pop_back();  
                }
                else {
                    s.pop_back(); 
                    element = 0; 
                    break;
                }
            }
            
            if (element != 0)
                s.push_back(element);
        }
    
        return s;
    }
};