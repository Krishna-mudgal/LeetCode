#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-router/description/?envType=daily-question&envId=2025-09-20

class Router {
public:
    set<vector<int>> st;
    queue<vector<int>> q;
    unordered_map<int, vector<int>> mp;
    int mx = -1;
    Router(int memoryLimit) {
        mx = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        // string s = tostring(source) + "-" + tostring(destination) + "-" + tostring(ti)
        if(st.find({source, destination, timestamp}) != st.end()) return false;

        if(st.size() >= mx) {
            auto p = q.front();
            q.pop();
            st.erase(p);
            int d = p[1];
            mp[p[1]].erase(mp[d].begin());
        }
        
        st.insert({source, destination, timestamp});
        q.push({source, destination, timestamp});
        mp[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        
        auto p = q.front();
        q.pop();
        st.erase(p);
        int d = p[1];
        mp[d].erase(mp[d].begin());
        if(mp[d].size() == 0) mp.erase(d);

        return p;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int ans = 0;
        if(mp.find(destination) == mp.end()) return 0;
        vector<int> &v = mp[destination];
        if(v.empty()) return 0;
        
        // Without Binary Search, getting T.L.E;
        // find least number greater than or equal to startTime
        int a = -1;
        int lo = 0, hi = v.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if(v[mid] >= startTime) {
                a = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        // find largest number less than or equal to endTime
        int b = -1;
        lo = 0, hi = v.size() - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;

            if(v[mid] <= endTime) {
                b = mid;
                lo = mid + 1;
            } else hi = mid - 1;

        }

        if(a != -1 && b != -1) ans += (b - a + 1);

        return ans;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */