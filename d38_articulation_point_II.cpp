/*
You are given an undirected graph with V vertices and E edges. The graph is represented
as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge
between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges,
increases the number of connected components in the graph.
Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  void DFS(int node, int parent, int& timer, vector<int>& disc, vector<int>& low, 
    vector<vector<int>>& adj, vector<int>& ap, unordered_map<int, bool>& visited) {
        
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;
        
        for(auto nbr : adj[node]) {
            if(!visited[nbr]) {
                DFS(nbr, node, timer, disc, low, adj, ap, visited);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] >= disc[node] && parent != -1) 
                    ap.push_back(node);
                child++;
            }
            else if(nbr != parent) {
                low[node] = min(low[node], disc[nbr]);
            }
        }
         
        if(parent == -1 && child > 1)
            ap.push_back(node);
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
     
        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        unordered_map<int, bool> visited;

        vector<int> ap;
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, -1, timer, disc, low, adj, ap, visited);
            }
        }
        
        if(ap.empty()) 
            return {-1};
            
        sort(ap.begin(), ap.end());
        ap.erase(unique(ap.begin(), ap.end()), ap.end());
        
        return ap;
    }
};









class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        
        for(int it : adj[node]) {
            if(!vis[it])
                dfs(it, adj, vis);
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
     
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            vector<bool> vis(V, false);
            vis[i] = true;
            
            int comp = 0;
            for(int it : adj[i]) {
                if(!vis[it]) {
                    dfs(it, adj, vis);
                    comp++;
                }
            }
            
            if(comp >= 2)
                ans.push_back(i);
        }
        
        if(ans.empty())
            return {-1};
            
        return ans;
    }
};