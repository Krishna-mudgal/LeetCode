#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();

        string ans = "0";
        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                string x = "";
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
                    else x += number[j];
                }
                if(x > ans){
                    ans = x;
                }
            }
        }

        return ans;

    }
};

class Solution { // method 2
public:
    string removeDigit(string number, char digit) {
        int n = number.size();

        string ans = "0";
        for(int i = 0; i < n; i++){
            if(number[i] == digit){
                string x = number.substr(0, i) + number.substr(i + 1, n);
                if(x > ans){
                    ans = x;
                }
            }
        }

        return ans;

    }
};