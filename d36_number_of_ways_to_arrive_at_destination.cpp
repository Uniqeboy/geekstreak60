/*
You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges,
represented as a 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an
undirected edge between nodes ui and vi that takes timei minutes to reach.
Your task is to return in how many ways you can travel from node 0 to node V - 1 in the
shortest amount of time.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> minTime(V, INT_MAX);
        
        vector<int> paths(V, 0);
        minTime[0] = 0;
        paths[0] = 1;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
    
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int currentTime = top.first;
    
            if (currentTime > minTime[node]) continue;
    
            for (auto& next : adj[node]) {
                int nextNode = next.first;
                int nextTime = next.second;
                int newTime = nextTime + currentTime;
                
                if (newTime < minTime[nextNode]) {
                    minTime[nextNode] = newTime;
                    paths[nextNode] = paths[node];
                    pq.push({newTime, nextNode});
                } else if (newTime == minTime[nextNode]) {
                    paths[nextNode] = (paths[nextNode] + paths[node]);
                }
            }
        }

        return paths[V - 1];
    }
};



class Solution {
  public:
    void dfs(int node, int curtime, vector<vector<pair<int,int>>>& adj,
                vector<int> vis, int V, int& shortest, int& ways) {
                    
        if(curtime > shortest)  return ;
        
        if(node == V-1) {
            if (curtime < shortest) {
                shortest = curtime;
                ways = 1;
            }
            else if (curtime == shortest)
                ways++;
            return;
        }
        
        vis[node] = 1;
        for (auto &p : adj[node]) {
            int next = p.first;
            int wt = p.second;
            if (vis[next] == 0) {
                dfs(next, curtime + wt, adj, vis, V, shortest, ways);
            }
        }
        
        vis[node] = 0;
    }
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        
        vector<int> vis(V, 0);
        int shortest = INT_MAX;
        int ways = 0;
        
        dfs(0, 0, adj, vis, V, shortest, ways);
        return ways;
    }
};