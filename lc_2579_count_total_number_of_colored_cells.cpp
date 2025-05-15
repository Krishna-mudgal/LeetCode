#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-total-number-of-colored-cells/description/?envType=daily-question&envId=2025-03-05

class Solution { // T.C = O(1)
    public:
        long long coloredCells(int n) {
            return 2*pow(n - 1, 2) + 2*n - 1;
        }
    };

class Solution { // T.C. = O(1)
public:
    long long coloredCells(int n) {
        return pow(n, 2) + pow(n - 1, 2);
    }
};

class Solution { // Tried dfs but don't know where is error 
    public:
    
        void helper(vector<vector<int> >&v, long long int &ans, int x, int y, int t, int &n){
            if(x < 0 || y < 0 || x >= v.size() || y >= v[0].size() || v[x][y] == 1 || t >= n) return;
    
            v[x][y] = 1;
            ans++;
    
            helper(v, ans, x + 1, y, t + 1, n);
            helper(v, ans, x - 1, y, t + 1, n);
            helper(v, ans, x, y + 1, t + 1, n);
            helper(v, ans, x, y - 1, t + 1, n);
        }
    
        long long coloredCells(int n) {
            vector<vector<int> > v(2*n - 1, vector<int> (2*n - 1, 0));
            long long ans = 0;
            int t = 0;
            helper(v, ans, n - 1, n - 1, t, n);
            return ans;
        }
    };