#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/keys-and-rooms/description/

class Solution {
public:
    
    void helper(vector<vector<int>> &r, unordered_set<int> &visited, int room_no){
        if(visited.find(room_no) != visited.end()) return; // if already visited then return
        if(room_no == r.size()) return;

        visited.insert(room_no);

        for(int i = 0; i < r[room_no].size(); i++){
            int x = r[room_no][i];

            if(visited.find(x) == visited.end()) { // means not visited then call helper function
                helper(r, visited, x);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        unordered_set<int> visited;
        helper(rooms, visited, 0);

        return visited.size() == n; // if all rooms are vistied then return true other wise return false;
    }
};