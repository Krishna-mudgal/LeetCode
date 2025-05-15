#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2024-09-04

class Solution { // T.C = O(nlogn) in worst
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        char dir = 'N';
        set<pair<int, int> >s;

        for(int i = 0; i < obstacles.size(); i++){
            s.insert({obstacles[i][0], obstacles[i][1]});
        }

        int x = 0, y = 0;
        int mx = 0;

        for(int i = 0; i < n; i++){
            if(commands[i] == -1){ // turn right
                if(dir == 'N') dir = 'E';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'S') dir = 'W';
                else dir = 'N';
            }
            else if(commands[i] == -2){ // turn left
                if(dir == 'N') dir = 'W';
                else if(dir == 'W') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else dir = 'N';
            }
            else{
                for(int j = 0; j < commands[i]; j++){
                    if(dir == 'N'){
                        if(s.find({x, y+1}) == s.end()) { // path is clear so robot can move
                            y++; 
                            mx = max(mx, x*x + y*y);
                        }
                        else break; // obstacle found so robo can't move
                    }
                    else if(dir == 'E'){
                        if(s.find({x+1, y}) == s.end()){ // path is clear so robot can move
                            x++; 
                            mx = max(mx, x*x + y*y);
                        }
                        else break; // obstacle found so robo can't move
                    }
                    else if(dir == 'S'){
                        if(s.find({x, y-1}) == s.end()) { // path is clear so robot can move
                            y--; 
                            mx = max(mx, x*x + y*y);
                        }
                        else break; // obstacle found so robo can't move
                    }
                    else {
                        if(s.find({x-1, y}) == s.end()) { // path is clear so robot can move
                            x--;
                            mx = max(mx, x*x + y*y);
                        }
                        else break; // obstacle found so robo can't move
                    }
                }   
            }
        }

        return mx;

    }
};