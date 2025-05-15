#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04

class Solution { //  greedy
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());
        int i = 0, j = n - 1;
        int sum = skill[0] + skill[n - 1];
        long long ans = 0;

        while(i < j){
            if(sum == skill[i] + skill[j]) ans += skill[i]*skill[j];
            else return -1;

            i++;
            j--;
        }

        return ans;

    }
};

class Solution {
public:
    long long dividePlayers(vector<int>& skill) { // time : O(n) // approach 2 // more optimised

        int n = skill.size();
        unordered_map<int, int> m;

        int t_sum = 0, t_teams = n/2;

        for(int i : skill){
            t_sum += i;
            m[i]++;
        }

        if(t_sum % t_teams != 0) return -1;

        int sum = t_sum/t_teams;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            int rem = sum - skill[i];
            if(m.find(rem) != m.end()){
                ans += rem*skill[i];

                m[rem]--;
                if(m[rem] == 0) m.erase(rem);
            }
            else return -1;
        }

        if(ans == 0) return -1;
        else return ans/2;
        
    }
};