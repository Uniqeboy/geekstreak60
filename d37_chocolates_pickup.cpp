/*
You are given a 2D matrix grid[][] of size n*m, where each cell grid[i][j] represents the
number of chocolates available at position (i, j).

Two robots are collecting chocolates from this grid:
Robot 1 starts at the top-left corner (0, 0)
Robot 2 starts at the top-right corner (0, m - 1)

Your task is to determine the maximum total number of chocolates both robots can collect
while following these rules:
    From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    When a robot visits a cell, it collects all the chocolates there.
    If both robots land on the same cell, the chocolates in that cell are collected only once.
    Robots cannot move outside the boundaries of the grid.
    Both robots must continue moving until they reach the bottom row of the grid.
*/
#include<bits/stdc++.h>
using namespace std;
// O(n*(m^2)) Time and O(n*(m^2)) Space
class Solution {
  public:
    int solve(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(r == n)
            return 0;
            
        if(c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN;
            
        if (dp[r][c1][c2] != -1) 
            return dp[r][c1][c2];
        
        vector<int> cases = {-1, 0, 1};
        int ans = 0;
        
        for(int d1 : cases)
            for(int d2 : cases)
                ans = max(ans, solve(r+1, c1+d1, c2+d2, grid, dp));
        
        ans += grid[r][c1];
        
        if(c1 != c2)
            ans += grid[r][c2];
            
        return dp[r][c1][c2] = ans;
    }
    
    int maxChocolate(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, -1)));
        return solve(0, 0, m-1, grid, dp);
    }
};






// O(9^n) Time and O(n) Space
class Solution {
  public:
    int solve(int r, int c1, int c2, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(r == n)
            return 0;
            
        if(c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return INT_MIN;
            
        vector<int> cases = {-1, 0, 1};
        int ans = 0;
        
        for(int d1 : cases)
            for(int d2 : cases)
                ans = max(ans, solve(r+1, c1+d1, c2+d2, grid));
        
        ans += grid[r][c1];
        
        if(c1 != c2)
            ans += grid[r][c2];
            
        return ans;
    }
    
    int maxChocolate(vector<vector<int>>& grid) {
        return solve(0, 0, grid[0].size()-1, grid);
    }
};