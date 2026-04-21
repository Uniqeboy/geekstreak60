/*
You are at the side of a river. You are given a m litre jug and a n litre jug.
Both the jugs are initially empty. The jugs dont have markings to allow measuring
smaller quantities. You have to use the jugs to measure d litres of water.
Determine the minimum no of operations to be performed to obtain d litres of water in one of the jugs.

The operations you can perform are:
Empty a Jug
Fill a Jug
Pour water from one jug to the other until one of the jugs is either empty or full.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
      int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    int pour(int fromCap, int toCap, int d) {
        int from = fromCap, to = 0;
        
        int step = 1; 
        while (from != d && to != d) {
            int temp = min(from, toCap - to);
    
            to += temp;
            from -= temp;
            step++;
    
            if (from == d || to == d)
                break;
    
            if (from == 0)
            {
                from = fromCap;
                step++;
            }
        
            if (to == toCap)
            {
                to = 0;
                step++;
            }
        }
        return step;
    }

    int minSteps(int m, int n, int d) {
        if (m > n)
            swap(m, n);
        
        if (d > n)
            return -1;
    
        if (d % gcd(m, n) != 0)
            return -1;
    
        return min(pour(n, m, d), pour(m, n, d));
    }
};




class Solution {
  public:
    int minSteps(int m, int n, int d) {
        if (d > max(m, n)) return -1;
        
        queue<vector<int>> q;
        vector<vector<bool>> visited(m + 1, 
                                vector<bool>(n + 1, false));
        q.push({0, 0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            int jug1 = curr[0];
            int jug2 = curr[1];
            int steps = curr[2];
            
            if (jug1 == d || jug2 == d) return steps;
            
            if (!visited[m][jug2]){
                visited[m][jug2] = true;
                q.push({m, jug2, steps + 1});
            }
    
            if (!visited[jug1][n]){
                visited[jug1][n] = true;
                q.push({jug1, n, steps + 1});
            }
    
            if (!visited[0][jug2]){
                visited[0][jug2] = true;
                q.push({0, jug2, steps + 1});
            }
    
            if (!visited[jug1][0]){
                visited[jug1][0] = true;
                q.push({jug1, 0, steps + 1});
            }
    
            int pour1to2 = min(jug1, n - jug2);
            if (!visited[jug1 - pour1to2][jug2 + pour1to2]){
                visited[jug1 - pour1to2][jug2 + pour1to2] = true;
                q.push({jug1 - pour1to2, jug2 + pour1to2,
                                                    steps + 1});
            }
    
            int pour2to1 = min(jug2, m - jug1);
            if (!visited[jug1 + pour2to1][jug2 - pour2to1]){
                visited[jug1 + pour2to1][jug2 - pour2to1] = true;
                q.push({jug1 + pour2to1, jug2 - pour2to1,
                                                    steps + 1});
            }
        }
        return -1;
    }
};