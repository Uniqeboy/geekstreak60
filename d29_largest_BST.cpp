/*
You're given a binary tree. Your task is to find the size of the largest subtree within
this binary tree that also satisfies the properties of a Binary Search Tree (BST).
The size of a subtree is defined as the number of nodes it contains.
Note: A subtree of the binary tree is considered a BST if for every node in that
subtree, the left child is less than the node, and the right child is greater than
the node, without any duplicate values in the subtree.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};

info solve(Node* root, int& ans) {
    if(!root)
        return {INT_MIN, INT_MAX, true, 0};
        
        
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info curnode;
    curnode.maxi = max(root->data, right.maxi);
    curnode.mini = min(root->data, left.mini);
    curnode.size = left.size + right.size + 1;
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        curnode.isBST = true;
    else
        curnode.isBST = false;
        
    if(curnode.isBST)
        ans = max(ans, curnode.size);
        
    return curnode;
}

class Solution {
  public:
    int largestBst(Node *root) {
        int maxsize = 0;
        solve(root, maxsize);
        return maxsize;
    }
};