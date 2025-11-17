#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int maxProduct(vector<int>& nums) { // T.C. = O(n)
        int n = nums.size();

        // if there are odd negative ele -> then when ever you got negative check for prefix and suffix product without including this element and also separtely check only for this element.
        // if there are even negative ele -> then also check for prefix and suffix product with also including this element and also separtely check for this element only.
        // if you got 0, then do similar to what you do in case 1.

        // suffix ya prefix nikalte time age phle ka product 0 h to ab fresh shuruaat kro new subarray create krke from at this point

        int ans = INT_MIN;
        vector<int> prefix(n), suffix(n);
        int p = 1;
        for(int i = 0; i < n; i++) {
            if(p == 0) p = 1;
            p *= nums[i];
            prefix[i] = p;
        }

        p = 1;
        for(int i = n - 1; i >= 0; i--) {
            if(p == 0) p = 1;
            p *= nums[i];
            suffix[i] = p;
        }
        
        bool even_neg = true;
        for(int i : nums) if(i < 0) even_neg = !even_neg;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(i + 1 < n) ans = max(ans, suffix[i + 1]);
                if(i - 1 > 0) ans = max(ans, prefix[i - 1]);
                ans = max(ans, nums[i]);
            } else if(nums[i] < 0) {
                if(even_neg) ans = max(ans, max(prefix[i], max(suffix[i], nums[i])));
                else {
                    if(i + 1 < n) ans = max(ans, suffix[i + 1]);
                    if(i - 1 > 0) ans = max(ans, prefix[i - 1]);
                    ans = max(ans, nums[i]);
                }
            } else ans = max(ans, max(prefix[i], max(suffix[i], nums[i])));
        }

        return ans;
    }
};

class Solution { // T.C. = O(n)^2
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            int m = 1;
            for(int j = i; j < n; j++) {
                m *= nums[j];
                ans = max(ans, m);
            }
        }

        return ans;
    }
};