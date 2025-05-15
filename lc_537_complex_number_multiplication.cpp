#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/complex-number-multiplication/description/

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // num1 -> a1 + b1*i
        // num2 -> a2 + b2*i
        // real -> a1*a2 - b1*b2
        // imaginary -> a1b2 + b1a2
        
        int a1 = INT_MIN, b1 = INT_MIN;
        int n1 = num1.size(), n2 = num2.size();
        int i = 0;
        string x = "";
        bool flag = false;
        while(i < n1){
            if(isdigit(num1[i])){
                while(i < n1 && isdigit(num1[i])){
                    x += num1[i];
                    i++;
                }
                if(x != "") {
                    if(a1 == INT_MIN){
                        a1 = stoi(x);
                        if(flag){
                            a1 = -a1;
                            flag = false;
                        }
                    }
                    else{
                        b1 = stoi(x);
                        if(flag){
                            b1 = -b1;
                            flag = false;
                        }
                    }
                }
                x = "";
            }
            else if(num1[i] == '-') {
                flag = true;
                i++;
            }
            else i++;
        }
        i = 0;
        x = "";
        int a2 = INT_MIN, b2 = INT_MIN;
        while(i < n2){
            if(isdigit(num2[i])){
                while(i < n2 && isdigit(num2[i])){
                    x += num2[i];
                    i++;
                }
                if(x != "") {
                    if(a2 == INT_MIN){
                        a2 = stoi(x);
                        if(flag){
                            a2 = -a2;
                            flag = false;
                        }
                    }
                    else{
                        b2 = stoi(x);
                        if(flag){
                            b2 = -b2;
                            flag = false;
                        }
                    }
                }
                x = "";
            }
            else if(num2[i] == '-') {
                flag = true;
                i++;
            }
            else i++;
        }

        cout << a1 << " " << b1 << " " << a2 << " " << b2;

        return to_string(a1*a2 - b1*b2) + "+" + to_string(a1*b2 + b1*a2) + "i";
    }
};