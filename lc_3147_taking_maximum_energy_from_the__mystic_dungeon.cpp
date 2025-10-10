#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/?envType=daily-question&envId=2025-10-10

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) { // T.C. = O(n)
        int n = energy.size();

        for(int i = n - 2; i >= 0; i--) {
           if(i + k < n) energy[i] += energy[i + k];
        }

        return *max_element(energy.begin(), energy.end());
    }
};