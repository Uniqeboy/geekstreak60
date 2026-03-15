/*
Given the root of a Binary Tree, find the vertical traversal of the tree starting
from the leftmost level to the rightmost level.
Note: If there are multiple nodes passing through a vertical line, then they
should be printed as they appear in level order traversal of the tree.
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        unordered_map<int, vector<int>> lst;
        
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        
        int mn = 0, mx = 0;
        
        while (!q.empty()) {
            auto c = q.front();
            mn = min(mn, c.second);
            mx = max(mx, c.second);
            q.pop();
            
            lst[c.second].push_back(c.first->data);
          
            if (c.first->left)
                q.push({c.first->left, c.second - 1});
           
            if (c.first->right)
                q.push({c.first->right, c.second + 1});
        }
       
        vector<vector<int>> res;
        for (int i = mn; i <= mx; i++)
            res.push_back(lst[i]);
      
        return res;
    }
};