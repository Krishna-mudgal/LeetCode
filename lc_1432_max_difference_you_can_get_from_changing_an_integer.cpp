#include <bits/stdc++.h>
using namespace std;

class Solution { // brute force
public:
    
    int change(int x, string s, int y){
        int n = s.size();

        if(y == 9 && x == s[0] - '0' && x == 9){ // agr first place replace krna hai aur first place pr hi 9 h aur usko replace with 9 krna hai to iska krne ka koi mtlv ni h kyu ki wo whi bna rhega to tum left to right jaao aur agr koi bhi number other than 9 mile to usko replace krdo means uski jitni bhi occurences h unko replace krdo 
            for(int i = 0; i < n; i++){
                if(s[i] - '0' != x){
                    x = s[i] - '0';
                    break;
                }
            }
        }

        if(x == s[0] - '0' && y == 0){ // agr first place ko replace krna h with 0 to yh invalid hai to tum left to right jao aur agr koi number other than 0 and x mil jye to uski jitni bhi occurences h usko bdl do ab agr tum x ke sath ni dekhoge to syd tumhe left to right m x hi mil jye aur tum usi ko replace krdo to wo phir se incvalid hojyga isliye x ke sath dekhna bhi jruri hai
            for(int i = 0; i < n; i++){
                if(s[i] - '0' != x && s[i] - '0' != 0) {
                    x = s[i] - '0';
                    break;
                }
            }
            if(x == s[0] - '0') return stoi(s);
        }

        string t = s;
        for(int i = 0; i < n; i++){
            if(t[i] - '0' == x) t[i] = (char)(y + '0');
        }

        return stoi(t);
    }

    int maxDiff(int num) {

        string s = to_string(num);
        int ans = 0;

        for(int i = 0; i <= 9; i++){
            int a ;
            a = change(s[0] - '0', s,  i);
            int b;
            for(int j = 0; j <= 9; j++){
                b = change(s[0] - '0', s, j);
                cout << a << " " << b << endl;
                ans = max(ans, abs(a - b));
            }
        }

        return ans;

    }
};

class Solution { // optimised with greedy
public:
    
    int change(int x, string s, int y){
        int n = s.size();

        if(y == 9 && x == s[0] - '0' && x == 9){ // agr first place replace krna hai aur first place pr hi 9 h aur usko replace with 9 krna hai to iska krne ka koi mtlv ni h kyu ki wo whi bna rhega to tum left to right jaao aur agr koi bhi number other than 9 mile to usko replace krdo means uski jitni bhi occurences h unko replace krdo 
            for(int i = 0; i < n; i++){
                if(s[i] - '0' != x){
                    x = s[i] - '0';
                    break;
                }
            }
        }

        if(x == s[0] - '0' && y == 0){ // agr first place ko replace krna h with 0 to yh invalid hai to tum left to right jao aur agr koi number other than 0 and x mil jye to uski jitni bhi occurences h usko bdl do ab agr tum x ke sath ni dekhoge to syd tumhe left to right m x hi mil jye aur tum usi ko replace krdo to wo phir se incvalid hojyga isliye x ke sath dekhna bhi jruri hai
            for(int i = 0; i < n; i++){
                if(s[i] - '0' != x && s[i] - '0' != 0) {
                    x = s[i] - '0';
                    break;
                }
            }
            if(x == s[0] - '0') return stoi(s);
        }

        string t = s;
        for(int i = 0; i < n; i++){
            if(t[i] - '0' == x) t[i] = (char)(y + '0');
        }

        return stoi(t);
    }

    int maxDiff(int num) {

        string s = to_string(num);
        int ans = 0;

        int a, b;
        a = change(s[0] - '0', s,  9);
        b = change(s[0] - '0', s, 0);
        ans = max(ans, abs(a - b));
        b = change(s[0] - '0', s, 1);
        ans = max(ans, abs(a - b));

        return ans;

    }
};