/*
Given the root of a binary tree, return the size of the tree. The size of a binary tree is the
total number of nodes in the tree.
*/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int getSize(Node* root) {
        if(root == NULL)
            return 0;
            
        return 1 + getSize(root->left) + getSize(root->right);
    }
};