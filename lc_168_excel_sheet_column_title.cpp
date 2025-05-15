#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while(columnNumber > 0){
            if(columnNumber <= 26) {
                ans += (char)(columnNumber + 64);
                break;
            }

            int ascii = columnNumber % 26;
            
            if(ascii == 0) {
                ascii = 26;
                columnNumber--;
            }

            columnNumber /= 26;

            ans += (char)(ascii + 64);
        }
 
        reverse(ans.begin(), ans.end());

        return ans;
    }
};