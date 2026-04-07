/*
You are given two arrays men[] and women[], each of length n, where:
    men[i] represents the preference list of the i-th man, ranking all women in order of preference.
    women[i] represents the preference list of the i-th woman, ranking all men in order of preference.

The task is to form n pairs (marriages) such that:
    Each man is matched with exactly one woman, and each woman is matched with exactly one man.

The matching is stable, meaning there is no pair (man, woman) who both prefer each other over their current partners.
It is guaranteed that a stable matching always exists. Return the stable matching from the men’s perspective, i.e.,
the one where men are considered for the final output.
Return an array result[] of size n, where result[i] denotes the index (0-based) of the woman matched with the i-th man.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool prefers(vector<vector<int>> &women, int w, int m, int m1) {
        for (int i = 0; i < women[w].size(); i++) {
            if (women[w][i] == m)
                return true;
            if (women[w][i] == m1)
                return false;
        }
        return false;
    }

    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();
    
        vector<int> wPartner(n, -1);   
        vector<int> mPartner(n, -1);   
        
        vector<int> next(n, 0);        
        vector<bool> freeMan(n, true);  
    
        int freeCount = n;
        while (freeCount > 0) {
            int m;
            for (m = 0; m < n; m++)
                if (freeMan[m])
                    break;
    
            int w = men[m][next[m]];
            next[m]++;
    
            if (wPartner[w] == -1) {
                wPartner[w] = m;
                mPartner[m] = w;
                freeMan[m] = false;
                freeCount--;
            }
            else {
                int m1 = wPartner[w];
    
                if (prefers(women, w, m, m1)) {
                    wPartner[w] = m;
                    mPartner[m] = w;
    
                    freeMan[m] = false;
                    freeMan[m1] = true;
                }
            }
        }
    
        return mPartner;
    }
};