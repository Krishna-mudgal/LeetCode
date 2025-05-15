#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/shifting-letters-ii/description/

// brute force but not accepted
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n, 0);
        for(int i = 0; i < shifts.size(); i++){
            bool flag = true;
            if(shifts[i][2] == 0) flag = false;

            for(int j = shifts[i][0]; j <= shifts[i][1]; j++){
                if(flag) v[j]++;
                else v[j]--;

                v[j] %= 26;
            }
        }

        for(int i = 0; i < n; i++){
            if(s[i] + v[i] >= 97) {
                if(s[i] + v[i] > 122) {
                    int xtra = s[i] + v[i] - 122;
                    s[i] = xtra + 97 - 1;
                }
                else s[i] += v[i];
            }
            else {
                int x = abs(s[i] + v[i] - 97);
                s[i] = 122 - x + 1;
            }
        }

        return s;
    }
};

class Solution { // concept used : Difference Array Technique
    public:
        string shiftingLetters(string s, vector<vector<int>>& shifts) {
    
            // this problem is based on difference array technique
            // isme jha se start krna h wha pr shift add krdo aur jha tk krna h uske ek baad tk agr out of bound ni h to us jgh -shift add krdo 
            // phir cummulative sum i.e. prefix sum nikalo to jha se start hona tha wha pr se shift add hone lgega aur jha pr end ho rha h wha tk add hoga phir uske chuki apn ne end ke ek baad -shift se add se kiya h to dono neutralize hojyge to phir uske baad 0 hi add hoga sab m
            
            // jaise initial h : 0, 0, 0, 0, 0, 0
            // add [1, 3, 10] -> [start, end, shift]
            // to start idx 1 pr shift add kro to ab array hoga : 0, 10, 0, 0, 0, 0
            // ab end idx 3 ke baad 4 pr -shift add kro to array hoga : 0, 10, 0, 0, -10, 0
            // ab prefix sum lo to array hoga : 0, 10, 10, 10, 0, 0
    
            // shift start se end tk to add hoga phir chuki end ke just baad -shift h to wo neutralize hojyga
    
            int n = s.size();
            vector<int> v(n, 0);
            for(int i = 0; i < shifts.size(); i++){
                int shift = 1;
                if(shifts[i][2] == 0) shift = -shift;
    
                v[shifts[i][0]] += shift;
                if(shifts[i][1] + 1 < n) v[shifts[i][1] + 1] += -shift;
            }
    
            v[0] %= 26;
            for(int i = 1; i < n; i++){
                v[i] += v[i - 1];
                v[i] %= 26;
            }
    
            for(int i = 0; i < n; i++){
                if(s[i] + v[i] >= 97) {
                    if(s[i] + v[i] > 122) {
                        int xtra = s[i] + v[i] - 122;
                        s[i] = xtra + 97 - 1;
                    }
                    else s[i] += v[i];
                }
                else {
                    int x = abs(s[i] + v[i] - 97);
                    s[i] = 122 - x + 1;
                }
            }
    
            return s;
        }
    };