#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/most-profit-assigning-work/

class Solution {
public:

    int helper(vector<int> &difficulty, unordered_map<int, int> &m, int lvl){
        int n = difficulty.size();
        int lo = 0, hi = n - 1;
        int ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(difficulty[mid] > lvl) hi = mid - 1;
            else {
                ans = max(ans, m[difficulty[mid]]);
                lo = mid + 1;
            }
        }

        return ans;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            if(mp.find(difficulty[i]) != mp.end()){
                mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]);
            }
            else mp[difficulty[i]] = profit[i];
        }

        sort(worker.begin(), worker.end());
        sort(difficulty.begin(), difficulty.end());

        int mx = 0;
        for(int i = 0; i < n; i++){ // basically x difficulty tk jitna mx profit mil skta h map m whi daal lo kyu binary search pta cha inital difficulty pr profit jada h aur mid baad m aya to apn mx profit store ni krpyge yhi issue a rha tha
            mx = max(mx, mp[difficulty[i]]);
            mp[difficulty[i]] = mx;
        }

        int ans = 0;
        int i = 0;
        int m = worker.size();
    
        while(i < m){
            ans += helper(difficulty, mp, worker[i]);
            i++;
        }

        return ans;
    }
};