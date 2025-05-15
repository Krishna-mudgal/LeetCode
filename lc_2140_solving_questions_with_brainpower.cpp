#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/solving-questions-with-brainpower/description/?envType=daily-question&envId=2025-04-01

class Solution { // T.C. = O(n) , top-down
    public:
        
        long long helper(vector<vector<int>> &q, vector<long long> &dp, int idx){
            if(idx >= q.size()) return 0;
            
            if(dp[idx] != -1) return dp[idx];
    
            long long x = 0;
            x = max((q[idx][0] + helper(q, dp, idx + q[idx][1] + 1)), helper(q, dp, idx + 1)); // max(taken_current, no_taken_current);
    
            return dp[idx] = x;
        }
    
        long long mostPoints(vector<vector<int>>& questions) {
            int n = questions.size();
            vector<long long> dp(n, -1);
    
            return helper(questions, dp, 0);
        }
    };


    class Solution { // bottom-up, T.c. = O(n)
        public:
            long long mostPoints(vector<vector<int>>& questions) {
                int n = questions.size();
                vector<long long> dp(n + 1, 0);
        
                dp[n - 1] = questions[n - 1][0];
                for(int i = n - 2; i >= 0; i--){
                    if(i + questions[i][1] + 1 < n) dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i + 1]);
                    else dp[i] = max((long long)questions[i][0], dp[i + 1]);
                }
        
                return dp[0];
            }
        };