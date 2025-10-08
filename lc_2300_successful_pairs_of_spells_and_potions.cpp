#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/?envType=daily-question&envId=2025-10-08

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) { // T.C. = O(n + m *(log(m)))
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end()); // O(m*log(m))

        vector<int> ans;
        for(int i = 0; i < n; i++) { // O(n)
            long long rem = success/spells[i];
            if(success % spells[i] != 0) rem++;

            int lo = 0,  hi = m - 1, idx = -1;
            while(lo <= hi) { // O(log(m))
                int mid = lo + (hi - lo)/2;

                if(potions[mid] >= rem) {
                    idx = mid;
                    hi = mid - 1;
                } else lo = mid + 1;
            }

            if(idx != -1) ans.push_back(m - idx);
            else ans.push_back(0);
        }

        return ans;
    }
};