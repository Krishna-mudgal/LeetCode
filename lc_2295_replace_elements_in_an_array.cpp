#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/replace-elements-in-an-array/description/

class Solution {
    public:
        vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
            unordered_map<int, int> m;
            for(int i = 0; i < nums.size(); i++){
                m[nums[i]] = i;
            }
    
            for(int i = 0; i < operations.size(); i++){
                if(m.find(operations[i][0]) != m.end()){
                    int idx = m[operations[i][0]];
                    nums[idx] = operations[i][1];
    
                    // storing element that is stored at idx after updation
                    m.erase(operations[i][0]);
                    m[operations[i][1]] = idx;
                }
            }
    
            return nums;
        }
    };

    // without using hashmap
    class Solution { // T.C. = O(max(nums.size(), operations.size()))
        public:
            vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
                vector<int> v(10000000, -1);
                for(int i = 0; i < nums.size(); i++){
                    v[nums[i]] = i;
                }
        
                for(int i = 0; i < operations.size(); i++){
                    if(v[operations[i][0]] != -1){
                        int idx = v[operations[i][0]];
                        nums[idx] = operations[i][1];
        
                        // storing element that is stored at idx after updation
                        v[operations[i][0]] = -1;
                        v[operations[i][1]] = idx;
                    }
                }
        
                return nums;
            }
        };