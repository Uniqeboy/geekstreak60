/*
You are given n courses, labeled from 0 to n - 1 and a 2d array prerequisites[][] where prerequisites[i] = [x, y]
indicates that we need to take course y first if we want to take course x.
Find if it is possible to complete all tasks. Return true if all tasks can be completed, or false if it is impossible.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1; 
    
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 1) {
                return false; 
            } else if (visited[neighbor] == 0) {
                if (!dfs(neighbor, adj, visited)) {
                
                    return false; 
                }
            }
        }
        
        visited[node] = 2; 
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& pre : prerequisites) {
            int dest = pre[0];
            int src = pre[1];
            adj[src].push_back(dest);
        }
        
        vector<int> visited(n, 0); 
        for (int i = 0; i < n; i++)
            if (visited[i] == 0)
                if (!dfs(i, adj, visited))
                    return false; 
        
        return true;
    }
};