#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        if(n == 1) return folder;

        vector<string> ans;
        unordered_set<string> st;
        sort(folder.begin(), folder.end());

        int i = 0, j = 1;
        while(j < n){
            string s1 = folder[i];
            string s2 = folder[j];

            vector<string> v1; // to store each folder name without '/' of str s1
            vector<string> v2; // to store each folder name without '/' of str s2
            
            // filling v1 from s1
            int a = 0;
            while(a < s1.size()){
                if(s1[a] == '/'){
                    a++;
                    string x = "";
                    while(a < s1.size() && s1[a] != '/'){
                        x += s1[a];
                        a++;
                    }
                    if(x != "") v1.push_back(x);
                }
            }

            // filling v2 from s2
            a = 0;
            while(a < s2.size()){
                if(s2[a] == '/'){
                    a++;
                    string x = "";
                    while(a < s2.size() && s2[a] != '/'){
                        x += s2[a];
                        a++;
                    }
                    if(x != "") v2.push_back(x);
                }
            }

            a = 0;
            while(a < v1.size() && a < v2.size()){
                if(v1[a] != v2[a]) { // if two folders of s1 and s2 are not equal that means they are different folders so move i kyu ki ange jo bhi folder milege wo ith folder ke subfolder ho hi ni skte 
                    i = j;
                    break;
                }
                a++;
            }

            if(a == v1.size()) st.insert(s2);

            j++;
        }

        for(auto s : folder){
            if(st.find(s) == st.end()) ans.push_back(s);
        }

        return ans;
    }
};