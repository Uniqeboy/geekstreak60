/*
Given two sorted arrays a[] and b[], where each array may contain duplicate elements,
return the elements in the intersection of the two arrays in sorted order.
Note: Intersection of two arrays can be defined as the set containing distinct common
elements that are present in both of the arrays.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        set<int> s;
        set_intersection(a.begin(), a.end(),
                         b.begin(), b.end(),
                         inserter(s, s.begin()));
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};