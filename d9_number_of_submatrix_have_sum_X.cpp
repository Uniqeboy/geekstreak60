/*
Given a matrix mat[][] of size n × m and an integer x, find the number of square submatrices whose sum of elements is equal to x.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquare(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                prefix[i][j] = mat[i-1][j-1] 
                             + prefix[i-1][j]
                             + prefix[i][j-1]
                             - prefix[i-1][j-1];
            }
        }
        
        int ans = 0;
        for(int size = 1; size <= min(n,m); size++){
            
            for(int i = 0; i + size <= n; i++){
                for(int j = 0; j + size <= m; j++){
                    
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + size;
                    int c2 = j + size;
                    
                    int sum = prefix[r2][c2]
                            - prefix[r1][c2]
                            - prefix[r2][c1]
                            + prefix[r1][c1];
                    
                    if(sum == x)
                        ans++;
                }
            }
        }
        
        return ans;
    }
};