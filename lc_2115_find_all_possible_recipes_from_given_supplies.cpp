#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

class Solution {
    public:
        bool check(unordered_map<string, vector<string>> &m, unordered_set<string> &s, string &recipe, unordered_set<string> &s1, unordered_set<string> &s2, unordered_set<string> &recipes_cant_make){
    
            if(s2.find(recipe) != s2.end() || recipes_cant_make.find(recipe) != recipes_cant_make.end()) return false; // means we are again going to recipe that required current recipe that means there is an infinite loop
    
            s2.insert(recipe);
            for(int i = 0; i < m[recipe].size(); i++){
                string x = m[recipe][i];
                if(s1.find(x) == s1.end()){
                    if(m.find(x) != m.end()) { // means it is a recipe
                        if(check(m, s, x, s1, s2, recipes_cant_make)) {
                            s1.insert(x);
                        }
                        else {
                            recipes_cant_make.insert(x);
                            return false;
                        }
                    }
                    else if(s.find(x) == s.end()) return false;
                }
            }
    
            return true;
        }
    
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            int n = recipes.size();
    
            unordered_set<string> s, s1, s2, recipes_cant_make; 
            // inserting recipes that we can create in s1 so that we don't have to check for it again
            // s2 is used to check if there is not an infinite loop
            // recipes_cant_make is to make sure if we found that a particular recipe can't be maked that we can't check it again in future
            unordered_map<string, vector<string>> m;
    
            for(int i = 0; i < n; i++){
                m[recipes[i]] = ingredients[i];
            }
    
            for(auto i : supplies) s.insert(i);
    
            vector<string> ans;
            for(int i = 0; i < n; i++){
                s2.clear();
                if(recipes_cant_make.find(recipes[i]) != recipes_cant_make.end()) continue;
    
                if(check(m, s, recipes[i], s1, s2, recipes_cant_make)) {
                    ans.push_back(recipes[i]);
                    s1.insert(recipes[i]);
                }
                else recipes_cant_make.insert(recipes[i]);
            }
    
    
            return ans;
        }
    };