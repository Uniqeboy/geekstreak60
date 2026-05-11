/*
Given an array arr[] consisting of n strings. Determine whether there exists a pair of indices (i, j)
such that i ≠ j and the concatenation arr[i] + arr[j] forms a palindrome.
Return true if such a pair exists; otherwise, return false.
Note: A string is considered a palindrome if it reads the same forward and backward.
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
  public:
    vector<TrieNode *> children;
    vector<int> indices;
    int idx;

    TrieNode() : idx(-1) {
        children.resize(26, nullptr);
    }
};

bool isPalindrome(string str, int i, int j) {
    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++, j--;
    }
    return true;
}

void insert(TrieNode *root, string word, int idx) {
    TrieNode *node = root;

    for (int i = word.length() - 1; i >= 0; i--) {
        if (isPalindrome(word, 0, i))
            (node->indices).push_back(idx);

        int index = word[i] - 'a';
        if (!node->children[index])
            node->children[index] = new TrieNode();

        node = node->children[index];
    }
    node->idx = idx;
    node->indices.push_back(idx);
}


bool search(TrieNode *root, string word, int idx) {
    TrieNode *node = root;
    for (int i = 0; i < word.length() && node; i++) {
        int index = word[i] - 'a';

        if (node->idx >= 0 && node->idx != idx && isPalindrome(word, i, word.size() - 1))
            return true;

        node = node->children[index];
    }

    if (node) {
        for (int i : node->indices) {
            if (idx != i)
                return true;
        }
    }

    return false;
}


class Solution {
  public:
    bool palindromePair(vector<string>& arr) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < arr.size(); i++)
            insert(root, arr[i], i);
    
        for (int i = 0; i < arr.size(); i++)
            if (search(root, arr[i], i))
                return true;
                
        return false;
    }
};