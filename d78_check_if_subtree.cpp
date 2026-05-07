/*
Given two binary trees with roots root1 (for tree T) and root2 (for tree S), each containing
at most N nodes. Determine whether tree S is a subtree of tree T.
Return true if S is a subtree of T, otherwise return false.

Note: A tree S is considered a subtree of T if there exists a node in T such that the subtree
rooted at that node is identical to S. Two trees are identical if they have the same structure and the same node values.
*/
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    bool areIdentical(Node* root1, Node* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true;
    
        if (root1 == nullptr || root2 == nullptr)
            return false;
    
        return (root1->data == root2->data &&
                areIdentical(root1->left, root2->left) &&
                areIdentical(root1->right, root2->right));
    }
    
    bool isSubTree(Node *root1, Node *root2) {
        if (root2 == nullptr)
            return true;
    
        if (root1 == nullptr)
            return false;
            
        if (areIdentical(root1, root2))
            return true;

        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
};