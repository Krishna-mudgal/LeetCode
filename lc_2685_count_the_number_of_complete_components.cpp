#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-the-number-of-complete-components/?envType=daily-question&envId=2025-03-22

class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> m;
            for(int i = 0; i < edges.size(); i++){
                m[edges[i][0]].push_back(edges[i][1]);
                m[edges[i][1]].push_back(edges[i][0]);
            }
    
            int ans = 0;
            unordered_set<int> s; // a visited set
            for(int i = 0; i < n; i++){
                if(m.find(i) == m.end()) {
                    ans++;
                    s.insert(i);
                }
                else if(s.find(i) != s.end()) continue; 
                else{
                    unordered_set<int> s1; // inserts total number of nodes in a subgraph
                    s1.insert(i);
                    s.insert(i);
    
                    for(auto y : m[i]){
                        s1.insert(y);
                        s.insert(y);
                    }
    
                    bool flag = false;
                    for(auto y : m[i]){
                        flag = false;
                        int cnt = 1;
                        for(auto k : m[y]){
                            if(s1.find(k) == s1.end()){ // if we find a element that is not connected to remaining nodes in that subgraph that this subgraph is not a complete connected component
                                flag = true;
                                break;
                            }
                            else cnt++;
                        }
                        if(flag) break;
                        if(cnt < s1.size()) { // this is to check a node is not connected to all nodes of a subgraph or not
                            flag = true;
                            break;
                        }
                    }
    
                    if(flag) continue;
                    else ans++;
                }
            }
    
            return ans;
        }
    };