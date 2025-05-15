#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/

class Solution { // T.C = O(n), S.C = O(k)
public:
    long long maximumSubarraySum(vector<int>& nums, int k) { // similar to fruit into basket
        int n = nums.size();

        unordered_map<int, int> m;

        int i = 0, j = 0;
        long long sum = 0, ans = 0;

        while(j < n){
            if(m.size() < k){
                if(m.find(nums[j]) == m.end()){ // agr element repeated ni h to usko to apn map m daal skte h
                    m[nums[j]]++;
                    sum += nums[j];
                    j++;
                }
                else{ // element repeat wala h
                    while(j < n && m.size() < k){
                        // isme repeated apne aap hi ht jyga kyu ki repeated ke ane s map ka size ni bdega to loop chlta rhega aur window agr k size ki hogyi h to ange bdti rhgi
                        m[nums[j]]++; 
                        if(j - i == k){ // agr meri window ka size k h to ab m i ko bhi ange bdaoga kyu ki phir size k se jada hojyga
                            m[nums[i]]--;
                            if(m[nums[i]] == 0) m.erase(nums[i]);
                            sum -= nums[i];
                            i++;
                        }

                        sum += nums[j];
                        j++;
                    }
                }
            }
            if(m.size() == k){
                ans = max(ans, sum);
                sum -= nums[i];
                m[nums[i]]--;
                if(m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
        }

        return ans;

    }
};