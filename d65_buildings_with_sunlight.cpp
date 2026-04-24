/*
Given the array arr[] of heights of certain buildings that lie adjacent to each other,
Sunlight starts falling from the left side of the buildings. If there is a building of
a certain height, all the buildings to the right side of it having lesser heights cannot see the sun.
Find the total number of buildings that receive sunlight.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 1;
            
        int ans = 1;
        int maxi = arr[0];
        
        for(int i = 1; i < n; i++) {
            if(arr[i] >= maxi) {
                maxi = arr[i];
                ans++;
            }
        }
        
        return ans;
    }
};