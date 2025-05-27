#include <bits/stdc++.h>
using namespace std;

class Solution { // T.C. = O((number_of_different_alphabets) * n) = O(n)
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int i = 0,  j = 0;
        int ans = 0;
        unordered_map<char, int> m;
        for(auto c : s) m[c]++;

        for(auto p : m){
            int i = 0, j = 0;
            int temp_k = k;
            // cout << p.first << endl;
            while(j < n){
                if(s[j] != p.first){
                    if(temp_k <= 0) {
                        while(i < n && temp_k <= 0){
                            if(s[i] != p.first) temp_k++;

                            i++;
                        }
                    }

                    temp_k--;
                }

                j++;
                ans = max(ans, j - i);

                // cout << i << " " << j << " " << ans << endl;
            }
        }

        return ans;
    }
};