/*
Given a string s of distinct characters and their corresponding frequency f[ ] i.e. character s[i]
has f[i] frequency. You need to build the Huffman tree and return all the huffman codes in preorder
traversal of the tree.

Note: While merging if two nodes have the same value, then the node which occurs at first will be
taken on the left of Binary Tree and the other one to the right, otherwise Node with less value will
be taken on the left of the subtree and other one to the right.
*/
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    pair<int,int> freq;
    char ch;
    Node* left;
    Node* right;
    
    Node(char ch, int f, int ind) {
        this->freq = {f, ind};
        this->ch = ch;
        this->left = NULL;
        this->right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        if(a->freq.first == b->freq.first)
            return a->freq.second > b->freq.second;
            
        return a->freq.first > b->freq.first;
    }
};

class Solution {
public:
    void traverse(Node* root, string s, vector<string>& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            if (s == "") s = "0";
            ans.push_back(s);
            return;
        }
        
        traverse(root->left, s + '0', ans);
        traverse(root->right, s + '1', ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        priority_queue<Node*, vector<Node*>, cmp> pq;

        for(int i = 0; i < s.size(); i++) {
            pq.push(new Node(s[i], f[i], i));
        }

        while(pq.size() > 1) {
            Node* one = pq.top(); pq.pop();
            Node* two = pq.top(); pq.pop();

            Node* root = new Node('\0',
            one->freq.first + two->freq.first,
            min(one->freq.second, two->freq.second));
        
            root->left = one;
            root->right = two;
            pq.push(root);
        }

        vector<string> ans;
        traverse(pq.top(), "", ans);

        return ans;
    }
};