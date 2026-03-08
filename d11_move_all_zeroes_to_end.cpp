/*
You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right
end while maintaining the relative order of the non-zero elements. The operation must be performed in place,
meaning you should not use extra space for another array.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int size = arr.size();
        int i = 0;
        int count = 0;
        while(i < size) {
            if(arr[i] != 0) {
                arr[count++] = arr[i];
            }
            i++;
        }
        
        while(count < size) {
            arr[count++] = 0;
        }
        
    }
};