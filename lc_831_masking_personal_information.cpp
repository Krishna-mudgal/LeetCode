#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/masking-personal-information/description/

class Solution {
public:

    char to_lower(char c){
        if(islower(c)) return c;
        else return c + 32;
    }

    string maskPII(string s) {
        int n = s.size();

        int idx = -1;

        for(int i = 0; i < n; i++) {
            if(s[i] == '@'){
                idx = i;
                break;
            }
        }

        if(idx != -1){
            string first = "";
            first += to_lower(s[0]);
            string last = "";
            last += to_lower(s[idx - 1]);
            string domain = "";
            bool flag = false;

            for(int i = 0; i < n; i++){
                if(s[i] == '@') flag = true;
                else if(s[i] == '.') domain += s[i];
                else if(flag) domain += to_lower(s[i]);
            }

            return first + "*****" + last + '@' + domain;
        }
        else {
            
            string country = "";
            string last_four = "";
            string middle_three = "";
            string first_three = "";

            int a = 0;
            int i = n - 1;

            while(i >= 0){
                if(isdigit(s[i])){
                    a++;
                    
                    if(last_four.size() < 4) last_four += s[i];
                    else if(middle_three.size() < 3) middle_three += '*';
                    else first_three += '*';

                }
                
                i--;
                if(a == 10) break;
            }

            bool flag = true;

            while(i >= 0){
                if(isdigit(s[i])) {
                    if(flag) {
                        country += '+';
                        flag = false;
                    }
                    country += '*';
                }

                i--;
            }

            reverse(last_four.begin(), last_four.end());

            return (country.size() > 0) ? (country + "-" + first_three + "-" + middle_three + "-" + last_four) : (first_three + "-" + middle_three + "-" + last_four);
        }
    }
};