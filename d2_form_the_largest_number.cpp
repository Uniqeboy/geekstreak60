/*
Given an array of integers arr[] representing non-negative integers, arrange them so that after
concatenating all of them in order, it results in the largest possible number. Since the result
may be very large, return it as a string.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(string &s1, string &s2)
    {
        return s1 + s2 > s2 + s1;
    }

    string findLargest(vector<int> &arr)
    {
        int n = arr.size();

        vector<string> v;
        for (int it : arr)
        {
            v.push_back(to_string(it));
        }

        sort(v.begin(), v.end(), cmp);

        if (v[0] == "0")
            return "0";

        string ans = "";

        for (string &s : v)
            ans += s;

        return ans;
    }
};