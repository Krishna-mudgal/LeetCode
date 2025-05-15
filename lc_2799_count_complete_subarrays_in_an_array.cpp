#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

class Solution { // T.C. = O(n^2)
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            unordered_set<int> s1, s2;
            for(int i : nums) s1.insert(i);
    
            for(int i = 0; i < n; i++){
                s2.clear();
                for(int j = i; j < n; j++){
                    s2.insert(nums[j]);
                    if(s2.size() == s1.size()) ans++;
                }
            }
    
            return ans;
        }
    };



class Solution { // T.C. = O(n)
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int n = nums.size();
            int ans = 0;
            unordered_set<int> s1;
            unordered_map<int, int> m;
            for(int i : nums) s1.insert(i);
    
            int i = 0, j = 0;
            while(j < n){
                m[nums[j]]++;
                
                if(m.size() == s1.size()){
                    while(m.size() == s1.size()) {
                        ans += n - j;
                        m[nums[i]]--;
                        if(m[nums[i]] == 0) m.erase(nums[i]);
                        i++;
                    }
                }
    
                j++;
            }
    
            while(i < n){
                if(m.size() == s1.size()){
                    ans++;
                    m[nums[i]]--;
                    if(m[nums[i]] == 0) m.erase(nums[i]);
                    i++;
                }
                else break;
            }
    
            return ans;
        }
    };