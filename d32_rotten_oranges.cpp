/*
Given a matrix mat[][], where each cell in the matrix can have values 0, 1 or 2 which has the
following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges
Your task is to determine the minimum time required so that all the oranges become rotten.
A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j),
(i, j-1), (i, j+1) (up, down, left and right) in a unit time.
Note: If it is impossible to rot every orange then simply return -1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isSafe(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    
    void dfs(vector<vector<int>> &mat, int i, int j, int time) {
        int n = mat.size();
        int m = mat[0].size();
    
        mat[i][j] = time;
    
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
        for (auto dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
    

            if (isSafe(x, y, n, m) && (mat[x][y] == 1 || mat[x][y] > time + 1)) {
                dfs(mat, x, y, time + 1);
            }
        }
    }
    
    int orangesRot(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
    
        int elapsedTime = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
    
                if (mat[i][j] == 2) {
                    dfs(mat, i, j, 2);
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 1)
                    return -1;

                elapsedTime = max(elapsedTime, mat[i][j] - 2);
            }
        }
        return elapsedTime;
    }
};