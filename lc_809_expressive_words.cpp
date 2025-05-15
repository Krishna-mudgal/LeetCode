#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/expressive-words/description/

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = words.size();

        int ans = 0;
        for(int k = 0; k < n; k++){
            string x = words[k];
            if(x.size() > s.size()) continue;

            int i = 0, j = 0;
            bool flag = true;
            while(i < s.size()){
                if(s[i] == x[j]){
                    int cnt1 = 0, cnt2 = 0;
                    int a = i, b = j;
                    while(a < s.size()){
                        if(s[i] == s[a]) {
                            a++;
                            cnt1++;
                        }
                        else break;
                    }

                    while(b < x.size()){
                        if(x[b] == x[j]){
                            b++;
                            cnt2++;
                        }
                        else break;
                    }

                    if((cnt1 < 3 && cnt1 != cnt2) || (cnt2 > cnt1)) {
                        flag = false;
                        break;
                    }

                    i = a;
                    j = b;
                }
                else {
                    flag = false;
                    break;
                }
            }

            if(flag && j == x.size()) ans++;

        }

        return ans;
    }
};