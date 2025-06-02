#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicate-letters/description/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> st;
        unordered_map<char, int> m;
        vector<bool> v(26, false);

        for(auto c : s) m[c]++;

        for(int i = 0; i < n; i++){
            auto c = s[i];

            m[c]--;
            if(m[c] == 0) m.erase(c);

            // for every character c check :
            // if stack is empty then push c and mark it in v
            // else if jo stack ke top me h wo bda h c se or ange bhi present hai (stack ka top) aur c ab tk stack mai dala bhi ni h to jb tk aisa h tb tk stack ke top ko pop krte raho or phir end mai c ko push krdena aur v me mark krdena
            // else if stack ke top se chota hai or ab tk stack mai dala bhi ni h to stack mai c ko push krdo or v mai bhi mark krdo

            if(st.empty()) {
                st.push(c);
                v[c - 'a'] = true;
            }
            else if(st.top() > c && m.find(st.top()) != m.end() && !v[c - 'a']){
                while(!st.empty() && st.top() > c && m.find(st.top()) != m.end()){
                    v[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(c);
                v[c - 'a'] = true;
            }
            else if(!v[c - 'a']) {
                st.push(c);
                v[c - 'a'] = true;
            }

        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};