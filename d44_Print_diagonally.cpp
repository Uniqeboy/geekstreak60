/*
Give a n * n square matrix mat[][], return all the elements of its anti-diagonals from top to bottom.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        int n = mat.size();
        
        if(n == 1)
            return {mat[0][0]};
        
        vector<int> ans;
        
        for(int i = 0; i < n; i++) {
            int col = i;
            int row = 0;
            

                ans.push_back(mat[row][col]);


            while(row < n && col >= 0) {
                ans.push_back(mat[row][col]);
                row++;
                col--;
            }
        }

        for(int i = 1; i < n; i++) {
            int col = n-1;
            int row = i;
            
            while(row < n && col >= 0) {
                ans.push_back(mat[row][col]);
                row++;
                col--;
            }
        }
        
        return ans;
    }
};