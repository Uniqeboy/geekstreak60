/*
You are given two arrays a[] and b[], return the Union of both the arrays in any order.
The Union of two arrays is a collection of all distinct elements present in either of the
arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.
Note: Elements of a[] and b[] are not necessarily distinct.
Note that, You can return the Union in any order but the driver code will print the result in sorted order only.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        int i = 0, j = 0;
         
        int as = a.size(), bs = b.size();
        while(i < as || j < bs) {
            if(i < as)
                s.insert(a[i]);
            if(j < bs)
                s.insert(b[j]);
                
            i++, j++;
        }
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};