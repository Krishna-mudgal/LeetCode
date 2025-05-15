#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

class Solution { // T.C. = O(n)
    public: // solved without extending array
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int ans = 0;
            int i = 0, j = 1;
            bool flag = true;
            unordered_set<int> st;
    
            while(flag){
                if(i == n - 1) flag = false;
    
                if(colors[i] == colors[j]){
                    int y = i;
                    bool flag2 = false;
                    bool flag3 = false;
                    while(colors[i] == colors[j]){
                        if(i == y && flag2) return 0; // means all values are same
    
                        flag2 = true;
                        i++;
                        j++;
                        if(i == n) flag = false;
                        i %= n;
                        j %= n;
                    }
                    st.insert(i);
                }
                else {
                    i++;
                    j++;
                    i %= n;
                    j %= n;
                }
            }
    
            if(st.size() == 0) return colors.size();
    
            int alter_tiles = 0;
            for(auto i : st){
                int a = i, b =  i + 1;
                b %= n;
                alter_tiles = 0;
                cout << i << endl;
                flag = false;
                while(colors[a] != colors[b]){
                    if(a == i && flag) break; // to make sure there is no infinite cycle in case when every one is alternate
                    flag = true;
                    alter_tiles++;
                    a++;
                    b++;
    
                    a %= n;
                    b %= n;
                    if(colors[a] == colors[b] && alter_tiles > 0) alter_tiles++;
                }
    
                // cout << alter_tiles;
    
                while(alter_tiles >= k){
                    alter_tiles--;
                    ans++;
                }
            }
    
            return ans;
        }
    };

class Solution { // T.C. = O(n) 
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            // solved by extending the array
            
            // agar last wale element se grp start ho rha h to starting ke k - 1 element dekhne pdege isliye unko piche lga do taki waps na ghumna pde
            for(int i = 0; i < k - 1; i++){
                colors.push_back(colors[i]);
            }
    
            int n = colors.size();
            int ans = 0;
            int i = 0, j = 0;
    
            while(j < n){
                if(j + 1 < n && colors[j] != colors[j + 1]) j++;
                else {
                    j++;
                    while(j - i >= k){
                        ans++;
                        i++;
                    }
                    i = j;
                }
            }
    
            return ans;
        }
    };