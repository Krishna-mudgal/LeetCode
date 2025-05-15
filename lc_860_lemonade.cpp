#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lemonade-change/description/

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int n = bills.size();
            int five = 0, ten = 0;
    
            for(auto i : bills){
                if(i == 5) {
                    five++;
                }
                else if(i == 10){
                    if(five == 0) return false;
                    five--;
                    ten++;
                }
                else {
                    if(ten == 0){ // 10 ka ni h to teen 5 ke dedo
                        if (five < 3) return false; 
                        else five -= 3;
                    }
                    else if(ten > 0){ // 10 ka h to ek 5 ka aur dedo
                        if(five == 0) return false;
                        else {
                            five -= 1;
                            ten -= 1;
                        }
                    }
                }
            }
    
            return true;
        }
    };