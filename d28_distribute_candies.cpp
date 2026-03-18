/*
You are given the root of a binary tree with n nodes, where each node contains a certain number
of candies, and the total number of candies across all nodes is n. In one move, you can select
any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur
between a parent and child in either direction.
The task is to determine the minimum number of moves required to ensure that every node in the
tree has exactly one candy.
Note: The testcases are framed such that it is always possible to achieve a configuration
in which every node has exactly one candy, after some moves.
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int solve(Node* root, int& ans) {
        if(!root)
            return 0;
        
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
        ans += abs(l) + abs(r);
        
        return root->data + l + r -1;
    }
    
    int distCandy(Node* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};