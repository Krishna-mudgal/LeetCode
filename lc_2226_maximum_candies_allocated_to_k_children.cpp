#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

class Solution { // T.C. = O(N∗Log(Max(Candies))
    public:
        bool check(vector<int> &candies, long long &k, int x){
            int n = candies.size();
    
            long long no_of_piles = 0;
            for(int i = 0; i < n; i++){
                no_of_piles += candies[i]/x;
                if(no_of_piles >= k) return true;
            }
    
            return false;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            int n = candies.size();
            int ans = 0;
    
            int mx = INT_MIN;
            for(int i = 0; i < n; i++){
                mx = max(mx, candies[i]);
            }
    
            int lo = 1, hi = mx;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
    
                if(check(candies, k, mid)) {
                    ans = max(ans, mid);
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
    
            return ans;
        }
    };