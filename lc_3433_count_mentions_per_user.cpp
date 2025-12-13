#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-mentions-per-user/description/?envType=daily-question&envId=2025-12-12

bool opt(vector<string> &v1, vector<string> &v2) {
    int t1 = stoi(v1[1]), t2 = stoi(v2[1]);
    if(t1 < t2) return true;
    else if(t1 == t2) return v1[0] == "OFFLINE";
    else return false;
}

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> ans(numberOfUsers, 0);
        unordered_map<int, int> offline;
        sort(events.begin(), events.end(), opt);
        for(auto &v : events) {
            if(v[0] == "MESSAGE") {
                int ctime = stoi(v[1]);
                for (auto it = offline.begin(); it != offline.end();) {
                    if (it->second <= ctime) it = offline.erase(it);
                    else ++it;
                }

                if(v[2] == "ALL") {
                    for(int i = 0; i < numberOfUsers; i++) ans[i]++;
                } else if(v[2] == "HERE") {
                    for(int i = 0; i < numberOfUsers; i++) if(offline.find(i) == offline.end()) ans[i]++;
                } else {
                    int idx = 2;
                    while(idx < v[2].size()) {
                        // cout << idx << endl;
                        string num = "";
                        while(idx < v[2].size() && v[2][idx] >= '0' && v[2][idx] <= '9') {
                            num += v[2][idx];
                            idx++;
                        }
                        // cout << num << endl;
                        int i = stoi(num);
                        ans[i]++;
                        idx += 3;
                    }
                }
            } else {
                int id = stoi(v[2]), time = stoi(v[1]);
                offline[id] = time + 60;
            }
        }

        return ans;
    }
};