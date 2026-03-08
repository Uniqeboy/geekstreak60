/*
Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on
different indexes) that satisfies a2 + b2 = c2, otherwise return false.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool pythagoreanTriplet(vector<int> &arr) { 
      	int n = arr.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(arr[i]);
    
        for (int i = 0; i < n - 1; i++)  {
            for (int j = i + 1; j < n; j++) {
              	
              	int a = arr[i];
              	int b = arr[j];

                int c = sqrt(a * a + b * b);
                
                if (c*c == a*a + b*b && st.find(c) != st.end())
                    return true;
            }
        }

        return false;
    }
};