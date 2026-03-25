/*
You are given an undirected graph, which has tree characteristics with V vertices numbered
from 0 to V-1 and E edges, represented as a 2D array edges[][], where each element
edges[i] = [u, v] represents an edge from vertex u to v.

You can choose any vertex as the root of the tree. Your task is to find all the vertices that,
when chosen as the root, result in the minimum possible height of the tree.

Note: The height of a rooted tree is defined as the maximum number of edges on the path from
the root to any leaf node.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (V < 2) {
            vector<int> centroids;
            for (int i = 0; i < V; i++)
                centroids.push_back(i);
            return centroids;
        }
    
        vector<int> deg(V);
        for (int i = 0; i < V; i++)
            deg[i] = adj[i].size();

        queue<int> leaves;
        for (int i = 0; i < V; i++)
            if (deg[i] == 1)
                leaves.push(i);
    
        int remNodes = V;
        while (remNodes > 2) {
            int leafCount = leaves.size();
            remNodes -= leafCount;
    
            for (int i = 0; i < leafCount; i++) {
                int leaf = leaves.front();
                leaves.pop();
    
                for (int neighbor : adj[leaf]) {
                    deg[neighbor]--;
                    if (deg[neighbor] == 1)
                        leaves.push(neighbor);
                }
                
                deg[leaf] = 0; 
            }
        }
    
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }
    
        return result;
    }
};



class Solution {
  public:
    int findHeight(int node, int parent, vector<vector<int>> &adj) {
        int height = 0;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                height = max(height, 1 + findHeight(neighbor, node, adj));
            }
        }
        return height;
    }
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> heights(V);
    
        for (int i = 0; i < V; i++) {
            heights[i] = findHeight(i, -1, adj);
        }
    
        int minHeight = *min_element(heights.begin(), heights.end());
    
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (heights[i] == minHeight)
                result.push_back(i);
        }
    
        return result;
    }
};