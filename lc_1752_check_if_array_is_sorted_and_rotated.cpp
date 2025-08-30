#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2025-02-02

class Solution {
public:

    bool helper(queue<int> q, vector<int> &nums){
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(q.front() != nums[i]) return false;
            
            q.push(q.front());
            q.pop();
        }

        return true;
    }

    bool check(vector<int>& nums) {
        int n = nums.size();

        vector<int> v = nums;
        sort(v.begin(), v.end());

        queue<int> q;
        for(int i : v) q.push(i);

        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
           
            if(helper(q, nums)) return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        int pivot = -1;
        for(int i = 0; i < n; i++){
            if(i == 0 && nums[i] > nums[i + 1]) pivot = i;
            else if(i == n - 1 && nums[i] < nums[i - 1]) pivot = i;
            else if(i > 0 && i < n - 1 && nums[i - 1] <= nums[i] && nums[i] > nums[i + 1]) pivot = i;

            if(pivot != -1) break;
        }


        if(pivot == -1) {
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[i - 1]) return false;
            }

            return true;
        } 

        if(nums[0] < nums[n - 1]) return false;
        int i = 0;
        while(i < pivot) {
            if(nums[i] > nums[i + 1]) return false;
            i++;
        }

        i = pivot + 1;
        while(i < n - 1) {
            if(nums[i] > nums[i + 1]) return false;
            i++;
        }

        return true;
    }
};