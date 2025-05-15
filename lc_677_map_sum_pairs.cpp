#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/map-sum-pairs/description/

class MapSum {
public:
    unordered_map<string, int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto p : m){
            bool flag = true;
            if(prefix.size() > p.first.size()) continue;
            
            for(int i = 0; i < prefix.size(); i++){
                if(prefix[i] != p.first[i]){
                    flag = false;
                    break;
                }
            }

            if(flag) ans += p.second;
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */