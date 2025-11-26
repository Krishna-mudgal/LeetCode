#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/smallest-integer-divisible-by-k/description/?envType=daily-question&envId=2025-11-25

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 2 || k == 5) return -1;
        // calculate rem value for next iteration in current iteration  only
        // rem = (n*10 + 1) % k, we know that (a + b) % k == (a%k + b%k) % k;
        // rem = (n*10 + 1) % k -> ((n%k)*(10%k) + 1%k)) % k -> (rem*(10%k) + 1) % k
        int n = 1;
        string s = "1";
        unordered_set<int> st; // will be used to store remainder
        int rem = n % k;
        while(st.find(rem) == st.end()) {
            if(rem == 0) return s.size();
            st.insert(rem);
            rem = (rem * (10 % k) + 1) % k;
            s += "1";
        }

        return -1;
    }
};