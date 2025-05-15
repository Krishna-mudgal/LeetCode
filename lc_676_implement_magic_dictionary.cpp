#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/implement-magic-dictionary/description/

class MagicDictionary {
public:
    vector<string> v;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        v = dictionary;
    }
    
    bool search(string s) {
        for(int i = 0; i < v.size(); i++){
            if(s.size() == v[i].size() && s != v[i]){
                int cnt = 0;
                int j = 0;
                while(j < s.size()){
                    if(s[j] != v[i][j]) cnt++;

                    j++;
                }
                if(cnt == 1) return true;
            }
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */