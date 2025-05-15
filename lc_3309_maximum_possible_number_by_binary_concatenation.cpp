#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/

class Solution { // approach - 1
public:
    string findB(int a){
        string s = "";

        while(a > 0){
            int last = a % 2;
            a /= 2;

            s += last + '0';
        }

        reverse(s.begin(), s.end());
        return s;
    }
    
    int bToD(string s){
        int x = 1;

        int ans = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            ans += (s[i] - '0')*x;

            x *= 2;
        }

        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        
        string s1 = findB(nums[0]);
        string s2 = findB(nums[1]);
        string s3 = findB(nums[2]);

        int n1 = bToD(s1 + s2 + s3);
        int n2 = bToD(s1 + s3 + s2);
        int n3 = bToD(s2 + s1 + s3);
        int n4 = bToD(s2 + s3 + s1);
        int n5 = bToD(s3 + s1 + s2);
        int n6 = bToD(s3 + s2 + s1);

        return max({ n1, n2, n3, n4, n5, n6 });
    }
};

bool cmp(string &a, string &b){
    return a + b > b + a;
}
class Solution { // approach - 2
public:
    string findB(int a){
        string s = "";

        while(a > 0){
            int last = a % 2;
            a /= 2;

            s += last + '0';
        }

        reverse(s.begin(), s.end());
        return s;
    }
    
    int bToD(string s){
        int x = 1;

        int ans = 0;

        for(int i = s.size() - 1; i >= 0; i--){
            ans += (s[i] - '0')*x;

            x *= 2;
        }

        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        int n = 3;

        vector<string> v(n);

        for(int i = 0; i < n; i++){
            v[i] = findB(nums[i]);
        }

        sort(v.begin(), v.end(), cmp);

        string s = "";
        for(int i = 0; i < n; i++) s += v[i];

        return bToD(s);

    }
};