#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/description/?envType=daily-question&envId=2025-06-06

class Solution { // T.C. = O(n)
public:
    string robotWithString(string s) {
        int n = s.size();

        // apne se ange jo bhi sbse chota element h usko v[i] m daalo
        // phir loop lgao from i to n
        // s[i] dekho agr wo v[i] se chota h to ans pe s[i] daal do or ab agr st.top bhi chota h v[i] se to pop krte rhao tb tk aisa h and ans m daalte raho

        string ans = "";
        stack<char> st;
        vector<char> v (n);
        char c = s[n - 1];
        for(int i = n - 1; i >= 0; i--) {
            v[i] = c;
            c = min(c, s[i]);
        }

        int i = 0;
        while(i < n) {
            if(s[i] > v[i]) {
                st.push(s[i]);
            }
            else {
                ans += s[i];
                while(!st.empty() && st.top() <= v[i]) {
                    ans += st.top();
                    st.pop();
                }
            }
            
            i++;
        }

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};