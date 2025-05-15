#include <bits/stdc++.h>
using namespace std;

class Solution { // this gives T.L.E
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            string x = "";
            x += s[i];

            int a_cnt = 0, e_cnt = 0, i_cnt = 0, o_cnt = 0, u_cnt = 0;
            
            for(int j = i; j < n; j++){
                x += s[j];

                if(s[j] == 'a') a_cnt++;
                else if(s[j] == 'e') e_cnt++;
                else if(s[j] == 'i') i_cnt++;
                else if(s[j] == 'o') o_cnt++;
                else if(s[j] == 'u') u_cnt++;

                if(a_cnt % 2 == 0 && e_cnt % 2 == 0 && i_cnt % 2 == 0 && o_cnt % 2 == 0 && u_cnt % 2 == 0) ans = max(ans, j - i + 1);
            }
        }

        return ans;

    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        vector<int> vowel(5, 0);
        unordered_map<string, int> m;
        string x = "00000"; // 0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
        m[x] = -1;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                vowel[0] = (vowel[0] + 1) % 2;
                x[0] = (char)(vowel[0] + '0');
            }
            else if(s[i] == 'e'){
                vowel[1] = (vowel[1] + 1) % 2;
                x[1] = (char)(vowel[1] + '0');
            } 
            else if(s[i] == 'i'){
                vowel[2] = (vowel[2] + 1) % 2;
                x[2] = (char)(vowel[2] + '0');
            }
            else if(s[i] == 'o'){
                vowel[3] = (vowel[3] + 1) % 2;
                x[3] = (char)(vowel[3] + '0');
            }
            else if(s[i] == 'u'){
                vowel[4] = (vowel[4] + 1) % 2;
                x[4] = (char)(vowel[4] + '0');
            }

            for(int j = 0; j < 5; j++) x[j] = vowel[j] + '0';

            if(m.find(x) != m.end()){
                ans = max(ans, i - m[x]);
            }
            else{
                m[x] = i;
            }
        }

        return ans;

    }
};