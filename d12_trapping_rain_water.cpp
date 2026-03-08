/*
Given an array arr[] with non-negative integers representing the height of blocks.
If the width of each block is 1, compute how much water can be trapped between the
blocks during the rainy season. 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int>& heights) {
        int size = heights.size();
    
        vector<int> maxLH(size);
        vector<int> maxRH(size);
    
        int totalWater = 0;
    
        maxLH[0] = heights[0];
        for (int index = 1; index < size; index++) {
            maxLH[index] = max(maxLH[index - 1], heights[index]);
        }
    
        maxRH[size - 1] = heights[size - 1];
        for (int index = size - 2; index >= 0; index--) {
            maxRH[index] = max(maxRH[index + 1], heights[index]);
        }
    
        for (int index = 1; index < size - 1; index++) {
            int boundaryHeight = min(maxLH[index], maxRH[index]);
            totalWater += boundaryHeight - heights[index];
        }
    
        return totalWater;
    }
};