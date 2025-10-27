#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2025-10-27

class Solution {
public:
    int numberOfBeams(vector<string>& bank) { // T.C. = O(n*m) where n is number of rows and m is the max number of characters in string
        int n = bank.size();

        int ans = 0;
        pair<int, int> last = {-1, 0};
        for(int i = 0; i < n; i++) {
            string s = bank[i];
            int cnt = 0;
            for(auto c : s) if(c == '1') cnt++;

            if(last.first != -1 && last.first + 1 <= i && cnt > 0) {
                ans += last.second * cnt;
                last = {i, cnt};
            }

            if(last.first == -1) last = {i, cnt};

        }

        return ans;
    }
};