/*
Given a directed graph with V vertices labeled from 0 to V-1 and a list of edges edges[][], where each edge
is represented as [u, v] indicating a directed edge from vertex u to vertex v, find a Mother Vertex of the graph.
A Mother Vertex is a vertex from which all other vertices can be reached.
If multiple such vertices exist, return the one with the smallest value.
If no such vertex exists, return -1.
*/
#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    void dfsFromVertex(int v, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor])
                dfsFromVertex(neighbor, visited, adj);
        }
    }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);
        
        vector<bool> visited1(V, false);
        int candidate = 0;
        for (int i = 0; i < V; i++) {
            if (!visited1[i]) {
                dfsFromVertex(i, visited1, adj);
                candidate = i;
            }
        }
    
        vector<bool> visited2(V, false);
        dfsFromVertex(candidate, visited2, adj);
        for (bool v : visited2)
            if (!v)
                return -1;
    
        return candidate;
    }
};