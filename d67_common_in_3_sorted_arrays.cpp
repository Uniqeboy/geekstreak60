/*
Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing
order across these arrays. If there are no such elements return an empty array.
Note: Ignore duplicates, include each common element only once in the output.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int an = a.size();
        int bn = b.size();
        int cn = c.size();
        
        int i = 0;
        int j = 0;
        int k = 0;
        
        vector<int> ans;
        
        while(i < an && j < bn && k < cn) {
            if(a[i] == b[j] && c[k] == a[i]) {
                if(ans.empty() || ans.back() != a[i])
                    ans.push_back(a[i]);
        
                i++;
                j++;
                k++;
            }
            else {
                int mn = min({a[i], b[j], c[k]});

                if(a[i] == mn) i++;
                if(b[j] == mn) j++;
                if(c[k] == mn) k++;
            }
        }
        
        return ans;
    }
};




class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                              vector<int> &arr3) {
                              
        unordered_set<int> s1(arr1.begin(),arr1.end());
        unordered_set<int> s2(arr2.begin(),arr2.end());
        unordered_set<int> s3(arr3.begin(),arr3.end());
        
        map<int,int> m;
        for(int it:s1){
            m[it]++;
        }
        
        for(int it:s2){
            m[it]++;
        } 
        
        for(int it:s3){
            m[it]++;
        }
        
        vector<int> v;
        
        for(auto pair:m){
            if(pair.second == 3){
                v.push_back(pair.first);
            }
        }
        return v;
    }
};