/*
Given an directed graph with V vertices numbered from 0 to V-1 and E edges, represented as a
2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.
Each node has at most one outgoing edge.
Your task is to find the length of the longest cycle present in the graph. If no cycle exists,
return -1.
Note: A cycle is a path that starts and ends at the same vertex.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dist) {
        visited[node] = true;
        int tempAns = -1;
        for (int nbr : adj[node]) {
            
            if (!visited[nbr]) {
                dist[nbr] = dist[node] + 1;
                tempAns = max(tempAns, dfs(nbr, adj, visited, dist));
            }
            
            else if (dist[nbr] != -1) {
                tempAns = max(tempAns, dist[node] - dist[nbr] + 1);
            }
        }

        dist[node] = -1;
        return tempAns;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<bool> vis(V, false);
        vector<int> dist(V, -1);
        int ans = -1;
    
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dist[i] = 0;
                ans = max(ans, dfs(i, adj, vis, dist));
            }
        }
        return ans;
    }
};
