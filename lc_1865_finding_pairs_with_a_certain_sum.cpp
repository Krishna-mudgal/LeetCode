#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06

class FindSumPairs {
public:
    vector<int> v1, v2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { // T.C. = O(v2.size())
        v1 = move(nums1);
        v2 = move(nums2);
        for(int i = 0; i < v2.size(); i++) m[v2[i]]++;
    }
    
    void add(int index, int val) {
        m[v2[index] + val]++;
        m[v2[index]]--;
        if(m[v2[index]] == 0) m.erase(v2[index]);
        v2[index] += val;
    }
    
    int count(int tot) { // T.C. = O(1000) -> O(1)
        int ans = 0;
        // for(int i : v1) cout << i << " ";
        // cout << endl;
        // for(int i : v2) cout << i << " ";
        // cout << endl;
        // for(auto p : m) cout << p.first << " " << p.second << endl;

        for(int i = 0; i < v1.size(); i++) {
            int rem = tot - v1[i];
            // cout << rem << endl;
            if(m.find(rem) != m.end()) ans += m[rem];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */