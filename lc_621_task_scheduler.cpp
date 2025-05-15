#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> m;

        for(char c : tasks) m[c]++;

        priority_queue<pair<int, char>> pq;

        for(auto p : m) pq.push({p.second, p.first});

        int ans = 0;

        while(!pq.empty()){
            auto p = pq.top(); // yh wala character ek baar dalne ke baad ab n times baad hi daal payege to iske liye n time ka ek loop lga lo kyu ki last char dekhne se ni hoga
            pq.pop();

            stack<pair<int, char>> st;
            ans++;
            p.first--;
            if(p.first > 0) st.push({p.first, p.second});

            for(int i = 0; i < n; i++){
                if(pq.size() == 0 && st.size() == 0) return ans; // it means ki ab koi bhi process ni bcha h

                pair<int, char> p2 = {-1, 'a'};
                if(pq.size() > 0){
                    p2 = pq.top();
                    pq.pop();
                }

                if(p2.first != -1){
                    p2.first--;
                    if(p2.first > 0) st.push({p2.first, p2.second});
                }
                
                ans++; // jb tk loop chl rha h ya to new character process ho rha hoga ya to cpu idle hoga to ans++ krte chlo 

            }

            while(!st.empty()){
                pq.push(st.top());
                st.pop();
            }
        }

        return ans;

    }
};