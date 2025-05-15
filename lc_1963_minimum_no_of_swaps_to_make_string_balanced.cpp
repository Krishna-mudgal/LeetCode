#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/?envType=daily-question&envId=2024-10-08

class Solution { // approach - 1
public:
    int minSwaps(string s) {
        int i = 0,n = s.size();
        stack<char> st;
        int ans = 0;

        int noo = 0, noc = 0;
        while(i < n){
            if(s[i] == '[') noo++;
            else if(s[i] == ']') noc++;

            if(noc > noo) {
                ans++;
                noo = 0;
                noc = 0;
            }

            i++;
        }

        if(ans % 2 != 0) return ((ans/2) + 1);
        return ans/2;
    }
};

class Solution { // also prints the correct string
public:
    int minSwaps(string s) {
        int i = 0,j = s.size()-1;
        int o1 = 0,o2 = 0,c1 = 0,c2 = 0;
        int ans = 0;
        while(i < j){
            if(o1 == c1 ){
                o1 = 0;
                c1 = 0;
            }
            if(o2 == c2){
                o2 = 0;
                c2 = 0;
            }
            if(s[i] == '[')o1 ++;
            if(s[i] == ']')c1 ++;
            if(s[j] == '[')o2 ++;
            if(s[j] == ']')c2 ++;

            if(c1 > o1 && o2 > c2){
                swap(s[i],s[j]);
                i++;
                j--;
                o2 = 0;
                c2 = 1;
                c1 = 0;
                o1 = 1;
                ans ++;
            }
            else {
                if(c1 <= o1)i++;
                if(o2 <= c2)j--;
            }
            
        }
        cout<<s<<" ";
        return ans;
    }
};