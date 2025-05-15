#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/boats-to-save-people/description/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();

        if(n == 1) return 1;

        sort(people.begin(), people.end());

        int ans = 0;
        int i = 0, j = n - 1;

        while(i <= j){
            if(i == j){
                ans++;
                break;
            }

            int w1 = people[i];
            int w2 = people[j];

            if(w1 + w2 <= limit){
                ans++;
                i++;
                j--;
            }
            else {
                ans++;
                j--;
            }
        }

        return ans;
    }
};  