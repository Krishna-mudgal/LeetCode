#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05

class Solution {
public:
    typedef long long ll;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<ll> ans;
        ll sum = 0;
        set<pair<ll, ll>> st1, st2;
        unordered_map<ll, ll> mp;
        for(int i = 0; i < k; i++) {
            ll freq = (mp.find(nums[i]) != mp.end()) ? mp[nums[i]] : 0;
            mp[nums[i]]++;
            if(st2.size() < x || st2.find({freq, nums[i]}) != st2.end()) {
                if(st2.find({freq, nums[i]}) != st2.end()) {
                    st2.erase({freq, nums[i]});
                    sum -= freq*nums[i];
                }
                st2.insert({mp[nums[i]], nums[i]});
                sum += mp[nums[i]]*nums[i];

            } else if(st2.begin() -> first < mp[nums[i]] || (st2.begin() -> first == mp[nums[i]] && st2.begin() -> second < nums[i])) {
                st1.erase({mp[nums[i]]-1, nums[i]});
                st1.insert(*(st2.begin()));
                sum -= st2.begin() -> first * st2.begin() -> second;
                st2.erase(st2.begin());
                st2.insert({mp[nums[i]], nums[i]});
                sum += mp[nums[i]]*nums[i];
            } else st1.insert({mp[nums[i]], nums[i]});
        }
        ans.push_back(sum);

        int i = 0, j = k;
        while(j < n) {
            if(st2.find({mp[nums[i]], nums[i]}) != st2.end()) {
                st2.erase({mp[nums[i]], nums[i]});
                sum -= mp[nums[i]]*nums[i];
                mp[nums[i]]--;
                st1.insert({mp[nums[i]], nums[i]});
                st2.insert(*prev(st1.end()));
                sum += (prev(st1.end()) -> first * prev(st1.end()) -> second);
                st1.erase(prev(st1.end()));
            } else {
                st1.erase({mp[nums[i]], nums[i]});
                mp[nums[i]]--;
                st1.insert({mp[nums[i]], nums[i]});
                if(st2.begin() -> first < prev(st1.end()) -> first || (st2.begin() -> first == prev(st1.end()) -> first && st2.begin() -> second < prev(st1.end()) -> second)) {
                    ll freq1 = prev(st1.end()) -> first, val1 = prev(st1.end()) -> second;
                    ll freq2 = st2.begin() -> first, val2 = st2.begin() -> second;

                    st1.erase({freq1, val1});
                    st1.insert({freq2, val2});

                    st2.erase({freq2, val2});
                    sum -= freq2*val2;
                    st2.insert({freq1, val1});
                    sum += freq1*val1;
                }
            }
            i++;

            if(mp.find(nums[j]) != mp.end()) {
                if(st2.find({mp[nums[j]], nums[j]}) != st2.end()) {
                    st2.erase({mp[nums[j]], nums[j]});
                    sum -= mp[nums[j]]*nums[j];
                    mp[nums[j]]++;
                    st1.insert({mp[nums[j]], nums[j]});
                    st2.insert(*prev(st1.end()));
                    sum += (prev(st1.end()) -> first * prev(st1.end()) -> second);
                    st1.erase(prev(st1.end()));
                } else {
                    st1.erase({mp[nums[j]], nums[j]});
                    mp[nums[j]]++;
                    st1.insert({mp[nums[j]], nums[j]});
                    if(st2.begin() -> first < prev(st1.end()) -> first || (st2.begin() -> first == prev(st1.end()) -> first && st2.begin() -> second < prev(st1.end()) -> second)) {
                        ll freq1 = prev(st1.end()) -> first, val1 = prev(st1.end()) -> second;
                        ll freq2 = st2.begin() -> first, val2 = st2.begin() -> second;

                        st1.erase({freq1, val1});
                        st1.insert({freq2, val2});

                        st2.erase({freq2, val2});
                        sum -= freq2*val2;
                        st2.insert({freq1, val1});
                        sum += freq1*val1;
                    }
                }
            } else {
                mp[nums[j]]++;
                if(st2.size() < x) {
                    st2.insert({mp[nums[j]], nums[j]});
                    sum += mp[nums[j]]*nums[j];
                } else if(st2.begin() -> first < mp[nums[j]] || (st2.begin() -> first == mp[nums[j]] && st2.begin() -> second < nums[j])) {
                    st1.insert(*st2.begin());
                    sum -= (st2.begin() -> first * st2.begin() -> second);
                    st2.erase(st2.begin());
                    st2.insert({mp[nums[j]], nums[j]});
                    sum += mp[nums[j]]*nums[j];
                } else st1.insert({mp[nums[j]], nums[j]});
            }
            j++;

            ans.push_back(sum);
        }

        return ans;
    }
};