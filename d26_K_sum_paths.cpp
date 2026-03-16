/*

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
    int countPaths(Node* node, int k, int currSum, unordered_map<int, int>& prefSums) {
      
        if (node == nullptr)
            return 0;
      
      	int pathCount = 0;
        currSum += node->data;
      	 
        if (currSum == k)
            pathCount++;

        pathCount += prefSums[currSum - k];
      
        prefSums[currSum]++;
    
        pathCount += countPaths(node->left, k, currSum, prefSums);
        pathCount += countPaths(node->right, k, currSum, prefSums);

        prefSums[currSum]--;
      	return pathCount;
    }
  public:
    int countAllPaths(Node *root, int k) {
        unordered_map<int, int> prefSums;
        return countPaths(root, k, 0, prefSums);
    }
};