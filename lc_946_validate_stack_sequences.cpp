#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/validate-stack-sequences/description/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        
        stack<int> st;
        int i = 0, j = 0;
        while(i < n){
            if(!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i++]);
            }
        }

        while(j < n){
            if(st.size() > 0 && st.top() == popped[j]){
                st.pop();
                j++;
            }
            else return false;
        }

        return true;
    }
};