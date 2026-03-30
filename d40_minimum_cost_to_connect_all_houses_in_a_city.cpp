/*
Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the
location of each house, the task is to find the minimum cost to connect all the houses of the city.
The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj)
i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int MD(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> H;
        
        vector<bool> vis(n, false);
        H.push({0, 0});

        int totalCost = 0;
        
        while (!H.empty()) {
            pair<int, int> p = H.top(); H.pop();
            int cost = p.first;
            int u = p.second;
    
            if (vis[u]) continue;
    
            vis[u] = true;
            totalCost += cost;
    
            for (int v = 0; v < n; ++v) {
                if (!vis[v]) {
                    int dist = MD(houses[u], houses[v]);
                    H.push({dist, v});
                }
            }
        }
        return totalCost;
    }
};