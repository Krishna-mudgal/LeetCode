#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-atoms/description/

class Solution { // algo is correct but giving T.L.E
public:
    string add(string &s1, string &num){
        if(num == "") return "";
        
        int n = stoi(num);
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += s1;
        }

        return ans;

    }
    string countOfAtoms(string s) {
        int n = s.size();

        stack<string> st1;
        stack<int> st2;

        int i = 0;
        while(i < n){
            if(isdigit(s[i])){
                string num = "";
                while(isdigit(s[i])){
                    num += s[i];
                    i++;
                }
                string t = "";
                while(st1.size() > 0){
                    string x = st1.top();
                    t += x;
                    st1.pop();
                    if(x[0] >= 65 && x[0] <= 90) break;
                }
                st1.push(add(t, num));
                num = "";
            }
            else if(s[i] == ')'){

                string temp = "";
                string num = "";
                while(st1.size() > 0 && st1.top() != "("){
                    temp += st1.top();
                    st1.pop();
                }

                st1.pop();

                i++;
                while(i < n && isdigit(s[i])){
                    num += s[i];
                    i++;
                }

                st1.push(add(temp, num));

            }
            else {
                string t = "";
                t += s[i];
                st1.push(t);
                i++;
            }
        }

        string t = "";

        while(st1.size() > 0){
            t += st1.top();
            st1.pop();
        }

        reverse(t.begin(), t.end());

        unordered_map<string, int> m;

        i = 0;
        while(i < t.size()){
            string a = "";
            a += t[i];
            while(i + 1 < t.size()){
                char ch = t[i + 1];
                if(ch >= 65 && ch <= 90) break;
                a += t[i + 1];
                i++;
            }
            m[a]++;
            i++;
        }

        vector<pair<string, int>> v;

        for(auto p : m){
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        string ans = "";

        for(int i = 0; i < v.size(); i++){
            ans += v[i].first;
            if(v[i].second != 1) ans += to_string(v[i].second);
        }

        return ans;

    }
};