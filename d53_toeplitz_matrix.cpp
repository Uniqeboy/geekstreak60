/*
A Toeplitz matrix (also known as a diagonal-constant matrix) is a matrix in which every
descending diagonal from left to right contains the same element.
Given a rectangular matrix mat, determine whether it is a Toeplitz matrix or not.
Implement the function isToeplitz(mat) that returns:
true if the matrix is a Toeplitz matrix
false otherwise
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            int row = i;
            int col = 0;
            int se = mat[row][col];
            while(row < m && col < n) {
                if(mat[row][col] != se)
                    return false;
                row++;
                col++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            int row = 0;
            int col = i;
            int se = mat[row][col];
            while(row < m && col < n) {
                if(mat[row][col] != se)
                    return false;
                row++;
                col++;
            }
        }
        return true;
    }
};