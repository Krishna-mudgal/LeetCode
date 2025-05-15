#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03

class Solution { // T.C. = O(n)
    public:
    
        int check(vector<int> &v1, vector<int> &v2){
            int n = v1.size();
    
            unordered_map<int, int> m;
            for(int i : v1) m[i]++;
    
            int max_freq_ele = -1, max_freq = -1;
            for(auto p : m){
                if(max_freq < p.second){
                    max_freq = p.second;
                    max_freq_ele = p.first;
                }
            }
    
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(v1[i] != max_freq_ele && v2[i] == max_freq_ele) ans++;
                else if(v1[i] != max_freq_ele && v2[i] != max_freq_ele) return -1;
            }
    
            return ans;
        }
    
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int  n = tops.size();
    
            int ans1 = -1, ans2 = -1;
            ans1 = check(tops, bottoms);
            ans2 = check(bottoms, tops);
    
            if(ans1 == -1) return ans2;
            else if (ans2 == -1) return ans1;
            else return min(ans1, ans2);
        }
    };