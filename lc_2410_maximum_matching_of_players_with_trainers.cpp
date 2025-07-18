#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13

class Solution { // O(nlogn + mlogm)
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();
        int i = 0, j = 0;
        int ans = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while(i < n && j < m){
            if(trainers[j] >= players[i]) {
                i++;
                j++;
                ans++;
            }
            else j++;
        }

        return ans;

    }
};