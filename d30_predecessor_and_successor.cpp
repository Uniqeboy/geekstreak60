/*
You are given the root of a BST and an integer key. You need to find the inorder predecessor
and successor of the given key. If either predecessor or successor is not found,
then set it to NULL.
Note: In an inorder traversal the number just smaller than the target is the predecessor
and the number just greater than the target is the successor.
*/

#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    Node* left;
    Node* right;
    int data;
    
    Node(int data) {
        this->left = NULL;
        this->left = NULL;
        this->data = data;
    }
};

class Solution {
  public:
    void order(Node* root, vector<pair<int, Node*>>& orr) {
        if(!root) return;
        
        order(root->left, orr);
        orr.push_back({root->data, root});
        order(root->right, orr);
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<pair<int, Node*>> orr;
        order(root, orr);
        
        int n = orr.size();
        if(n == 0) return {NULL, NULL};
        
        Node* pre = NULL;
        Node* suc = NULL;
        
        for(int i = 0; i < n; i++) {
            if(orr[i].first < key) {
                pre = orr[i].second;
            }
            if(orr[i].first > key) {
                suc = orr[i].second;
                break;
            }
        }
        
        return {pre, suc};
    }
};