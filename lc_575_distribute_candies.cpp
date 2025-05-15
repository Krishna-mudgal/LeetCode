#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distribute-candies/description/

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        unordered_set<int> s;

        for(auto i : candyType) s.insert(i);

        if(s.size() >= n/2) return n/2;
        else return s.size();

    }
};