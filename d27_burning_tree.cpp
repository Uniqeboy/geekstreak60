/*
Given the root of a binary tree and a target node, determine the minimum time required
to burn the entire tree if the target node is set on fire. In one second, the fire spreads
from a node to its left child, right child, and parent.
Note: The tree contains unique values.
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    Node* createmapping(Node* root, int target, map<Node*, Node*>& pm) {
        queue<Node*> q;
        Node* ans = NULL;
        pm[root] = NULL;
        q.push(root);
        
        while(!q.empty()) {
            Node* front = q.front();
            q.pop();
            
            if(front->data == target) {
                ans = front;                
            }
            
            if(front->left) {
                pm[front->left] = front;
                q.push(front->left);
            }
            
            if(front->right) {
                pm[front->right] = front;
                q.push(front->right);
            }
        }
        return ans;
    }
    
    int mintime(Node* tn, map<Node*, Node*>& pm) {
        queue<Node*> q;
        map<Node*, bool> vis;
        
        q.push(tn);
        vis[tn] = true;
        
        int ans = 0;
        
        while(!q.empty()) {
            int n = q.size();
            bool flag = false;
            
            for(int i = 0; i < n; i++) {
                Node* front = q.front();
                q.pop();
                
                if(front->left && !vis[front->left]) {
                    vis[front->left] = true;
                    q.push(front->left);
                    flag = true;
                }
                
                if(front->right && !vis[front->right]) {
                    vis[front->right] = true;
                    q.push(front->right);
                    flag = true;
                }
                
                if(pm[front] && !vis[pm[front]]) {
                    vis[pm[front]] = true;
                    q.push(pm[front]);
                    flag = true;
                }
            }
            
            if(flag)
                ans++;
        }
        return ans;
    }
    
    int minTime(Node* root, int target) {
        map<Node*, Node*> pm;
        Node* tn = createmapping(root, target, pm);
        int ans = mintime(tn, pm);
        return ans;
    }
};