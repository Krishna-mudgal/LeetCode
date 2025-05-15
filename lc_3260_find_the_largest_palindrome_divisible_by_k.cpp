#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-largest-palindrome-divisible-by-k/description/

class Solution { // this solution is correct but gives Time limited Exceeded
public:
    string largestPalindrome(int n, int k) {
        vector<int> v;
        if(n % 2 == 0) {
            v.resize(n/2, 9);
        }
        else v.resize((n/2) + 1, 9);

        return f(v, n, k);
    }

private : 

    string f(vector<int> &v, int &n, int &k){
        if(v[0] <= 0) return "-1";

        string s(n, '0');

        for(int i = 0; i < v.size(); i++){
            s[i] = s[n - 1 - i] = v[i] + '0' ;
        }

        int mid;
        if(n % 2 == 0) mid = (n/2) - 1;
        else mid = n/2;
        
        for(int i = 9; i >= 0; i--){
            s[mid] = i + '0';
            s[n - 1 - mid] = i + '0';

            long long int a = stoll(s);
            if(a % k == 0) return s;
        }

        for(int i = v.size() - 1; i >= 0; i--){
            if(v[i] == 0) v[i] = 9;
            else {
                v[i]--;
                return f(v, n, k);
            }
        }

        return "-1";

    }
};