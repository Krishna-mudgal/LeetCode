#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-date-to-binary/description/

class Solution {
public:
    string remove_zeroes(string s){
        string ans = "";
        int n = s.size();
        bool flag = false;

        for(int i = 0 ; i < n; i++){
            if(s[i] != '0') flag = true;
            if(flag) ans += s[i];
        }

        return ans;

    }
    string convertDateToBinary(string date) {
        int n = date.size();
        string y = "", m = "", d = "";
        for(int i = 0; i < n; i++){
            if(date[i] == '-') continue;
            if(i < 4) y += date[i];
            else if(i > 4 && i < 7) m += date[i];
            else d += date[i];
        }
        
        // convert year, month, date to binary
        bitset<32> y_b(stoi(y));
        bitset<32> m_b(stoi(m));
        bitset<32> d_b(stoi(d));

        // convert binary fromat to string
        y = y_b.to_string();
        m = m_b.to_string();
        d = d_b.to_string();

        // remove leading zeroes
        y = remove_zeroes(y);
        m = remove_zeroes(m);
        d = remove_zeroes(d);

        return y + "-" + m + "-" + d;
    }
};