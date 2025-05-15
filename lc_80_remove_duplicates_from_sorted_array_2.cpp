#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> m; // freq map

        for(int i = 0; i < n; i++) m[nums[i]]++;

        vector<int> v;
        for(auto p : m){
            if(p.second == 1) v.push_back(p.first);
            else if(p.second >= 2){
                v.push_back(p.first);
                v.push_back(p.first);
            }
        }

        sort(v.begin(), v.end());
        ans = v.size();

        for(int i = 0; i < v.size(); i++) nums[i] = v[i];

        return ans;

    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // better approach
        int n = nums.size();

        if(n == 1) return 1;

        int k = 2;
        int ans = 2;

        for(int i = 2; i < n; i++){
            if(nums[i] == nums[i - 1] && nums[i] == nums[i - 2]){
                if(nums[k - 1] == nums[k - 2]) continue;
                else{
                    k++;
                    ans++;
                }
            }
            else {
                nums[k] = nums[i];
                k++;
                ans++;
            }
        }

        return ans;

    }
};