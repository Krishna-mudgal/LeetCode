#include <bits/stdc++.h>
#include <numeric>
#include <cmath>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/fraction-addition-and-subtraction/description/

class Solution {
public:
    void evaluate(int a, int b, int c, int d, queue<int> &que){
        int p = a * d + c * b; // Numerator
        int q = b * d;          // Denominator

        // Simplify the fraction
        int g = __gcd(p, q);
        p /= g;
        q /= g;
   
        if(p != 0){
            que.push(p);
            que.push(q);
        }

    }
    string fractionAddition(string s) {
        int n = s.size();

        queue<int> q;
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '/'){
                string x = "";
                if(flag) {
                    x += '-';
                    flag = false;
                }
                if(s[i - 1] == '0') x += "10";
                else x += s[i - 1];
                
                q.push(stoi(x));
                x = "";

                x += s[i + 1];
                if(i + 2 < n && isdigit(s[i + 2])) x += s[i + 2];
                q.push(stoi(x));
                x = "";
            }
            else if(s[i] == '-') flag = true;

        }

        while(q.size() > 2){
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            if(q.empty()) break;
            int c = q.front();
            q.pop();
            int d = q.front();
            q.pop();

            evaluate(a, b, c, d, q);
        }

        if(q.size() == 0) return "0/1";

        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();
        if(a % b == 0) {
            a = a/b;
            b = 1;
        }

        if(a == 0) return "0/1";
        return to_string(a) + '/' + to_string(b);
    }
};