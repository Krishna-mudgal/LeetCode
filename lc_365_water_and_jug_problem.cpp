#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/water-and-jug-problem/description/

class Solution {
public:

    bool helper(int x, int y, int target, set<pair<int, int>> &st, int a, int b) {
        if(st.find({a, b}) != st.end()) return false;
        if(a == target || b == target || a + b == target) return true;
        st.insert({a, b});
        // empty a into b
        bool ans;
        if(a + b <= y) ans = helper(x, y, target, st, 0, a + b);
        else ans = helper(x, y, target, st, a - (y - b), y);

        if(ans) return true;

        // empty b into a
        if(a + b <= x) ans = helper(x, y, target, st, a + b, 0);
        else ans = helper(x, y, target, st, x, b - (x - a));

        if(ans) return true;

        // fill completely a
        ans = helper(x, y, target, st, x, b);
        if(ans) return true;
        // fill b completely
        ans = helper(x, y, target, st, a, y);
        if(ans) return true;
        // empty a
        ans = helper(x, y, target, st, 0, b);
        if(ans) return true;
        // empty b
        ans = helper(x, y, target, st, a, 0);
        return ans;
    }

    bool canMeasureWater(int x, int y, int target) {
        set<pair<int, int>> st;
        if(target > x + y) return false;
        return helper(x, y, target, st, 0, 0);
    }
};