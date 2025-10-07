#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        set<int> zeroes;
        unordered_map<int, int> mp2;
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                zeroes.insert(i);
            } else {
                if(mp.find(rains[i]) == mp.end()) mp[rains[i]] = i;
                else { 
                    // ek zero valid tbhi tk h jbtk kisi lake ko khali krne k liye use ni hua ho
                    // agr rains[i] lake number phle hi fill hochuka h to bs dekhlo ki last time jha pr fill hua tha uske ange koi bhi zero hai or wo valid h to usko use krlo or mark krdo ki is zero ka use hmne rains[i] ko khali krne k liye kiya h or us zero ko unvalid mark krdo
                    int last_fill = mp[rains[i]];
                    bool flag = true;
                    for(auto p : zeroes) {
                        if(p > last_fill && p < i) {
                            flag = false;
                            mp2[p] = rains[i];
                            zeroes.erase(p);
                            mp[rains[i]] = i;
                            break;
                        }
                    }

                    if(flag) return {};
                }
            }
        }

        for(int i = 0; i < n; i++) {
            if(rains[i] != 0) ans.push_back(-1);
            else if(mp2.find(i) != mp2.end()) ans.push_back(mp2[i]);
            else ans.push_back(1);
        }

        return ans;
    }
};