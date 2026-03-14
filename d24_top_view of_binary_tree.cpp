/*
You are given the root of a binary tree, and your task is to return its top view.
The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Note:
Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost
(closest to the root) node is included in the view. 
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
        left = nullptr;
        right = nullptr;
    }
};
class Solution {
    void dfs(Node *node, int hd, int le, map<int, pair<int, int>>& tn) {
        if(!node)
            return ;
            
        if(tn.find(hd) == tn.end() || tn[hd].second > le)
            tn[hd] = {node->data, le};
            
        dfs(node->left, hd - 1, le + 1, tn);
        dfs(node->right, hd + 1, le + 1, tn);
    }
    
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) 
            return ans;
        
        map<int, pair<int, int>> tn;
        dfs(root, 0, 0, tn);
        
        for (auto it : tn)
            ans.push_back(it.second.first);
        
        return ans;
    }
};