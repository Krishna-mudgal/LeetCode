#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-iv/description/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int m = arr.size();
        vector<bool> visited(m, false);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < m; i++) mp[arr[i]].push_back(i);
        int ans = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto t = q.front();
                q.pop();

                if(t == m - 1) return ans;
                int cat = arr[t];

                // cout << t << " " << cat << endl;
                while(mp.find(cat) != mp.end()) {
                    int nxt = mp[cat].back();
                    mp[cat].pop_back();
                    if(mp[cat].size() == 0) mp.erase(cat);

                    if(!visited[nxt]) {
                        q.push(nxt);
                        visited[nxt] = true;
                    }
                }

                if(t - 1 > 0 && !visited[t - 1]) {
                    q.push(t - 1);
                    visited[t - 1] = true;
                }
                if(t + 1 < m && !visited[t + 1]) {
                    q.push(t + 1);
                    visited[t + 1] = true;
                }

            }

            ans++;
        }

        return ans;
    }
};