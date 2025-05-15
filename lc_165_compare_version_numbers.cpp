#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/compare-version-numbers/description/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();

        int i = 0, j = 0;
        int ans = 0;

        int x, y;
        string a = "", b = "";
        while(i < n || j < m){

            if(i >= n) x = 0;
            if(j >= m) y = 0;

            while(i < n && version1[i] != '.'){
                a += version1[i];
                i++;
            }
            if((i < n && version1[i] == '.') || i == n){
                x = stoi(a);
                a = "";
                i++;
            }

            while(j < m && version2[j] != '.'){
                b += version2[j];
                j++;
            }
            if((j < m && version2[j] == '.') || j == m){
                y = stoi(b);
                j++;
                b = "";
            }

            cout << x << " " << y << endl;

            if(x > y) return 1;
            else if(x < y) return -1;
            
        }

        if(a != "") x = stoi(a);
        if(b != "") y = stoi(b);

        if(x > y) return 1;
        else if(x < y) return -1;
        else return 0;

    }
};