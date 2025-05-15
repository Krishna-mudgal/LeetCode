#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;
        for(auto i : s){
            if(s.find(i - 1) == s.end()){ // agr i - 1 element tha set m to ab i ke liye to total consecutive ki value km hi hojygi to agr ni h to hi calculate kro consecutive
            // ex if 0 and 1 both are present then if we have check for 0 then there is no need to check for 1 bcs ans for 1 is ((ans for 0) - 1)
                int c = 0;
                int x = i;
                while(true){
                    if(s.find(x) != s.end()) {
                        c++;
                        x++;
                    }
                    else break;
                }

                ans = max(ans, c);
            }
        }

        return ans;

    }
};

class Solution { // 2nd approach
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;

        int ans = 0;
        sort(nums.begin(), nums.end());
        int cnt = 1; // counting 1st element
        for(int i = 0; i < n - 1; i++){
            if(nums[i] == nums[i + 1]) continue;
            else if(nums[i] + 1 == nums[i + 1]) cnt++;
            else{
                ans = max(cnt, ans);
                cnt = 1;
            }
        }

        ans = max(cnt, ans);
        return ans;

    }
};