#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17


// set with cmp is accepted
struct cmp { 
    bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) const {
        if (p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

// bool cmp(auto &p1, auto &p2) {
//     if (p1.first == p2.first)
//         return p1.second < p2.second;
//     return p1.first > p2.first;
// }

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>, cmp>> mp1;
    unordered_map<string, int> mp2; // to track rating of each food
    unordered_map<string, string> mp3; // to track food and cuisines
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {    
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            mp2[foods[i]] = ratings[i];
            mp3[foods[i]] = cuisines[i];
            mp1[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = mp3[food];
        int oldRating = mp2[food];
        mp1[c].erase({oldRating, food});
        mp1[c].insert({newRating, food});
        mp2[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return mp1[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */


//  ---------------------------------------------------------------------------------------------


// struct cmp {
//     bool operator()(const pair<int, string>& p1, const pair<int, string>& p2) const {
//         if (p1.first == p2.first)
//             return p1.second < p2.second;
//         return p1.first > p2.first;
//     }
// };

// bool cmp(auto &p1, auto &p2) {
//     if (p1.first == p2.first)
//         return p1.second < p2.second;
//     return p1.first > p2.first;
// }

class FoodRatings {
public:

    // If you don't want to use cmp then add your rating as negative and by default set sorts in asceding order so min value will be at begin and if 2 foods have same rating then they are placed lexographically smallest.
    // add rating in negative so the max rating will become sabse min rating and hence we can use it 

    unordered_map<string, set<pair<int, string>>> mp1;
    unordered_map<string, int> mp2; // to track rating of each food
    unordered_map<string, string> mp3; // to track food and cuisines
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {    
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            mp2[foods[i]] = -1*ratings[i];
            mp3[foods[i]] = cuisines[i];
            mp1[cuisines[i]].insert({-1*ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = mp3[food];
        int oldRating = mp2[food];
        mp1[c].erase({oldRating, food});
        mp1[c].insert({-1*newRating, food});
        mp2[food] = -1*newRating;
    }
    
    string highestRated(string cuisine) {
        return mp1[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

//  ---------------------------------------------------------------------------------------------


class FoodRatings { // This is a priority-queue solution but it is giving T.L.E
public:
    unordered_map<string, priority_queue<pair<int, string>>> mp1;
    unordered_map<string, int> mp2; // to track rating of each food
    unordered_map<string, string> mp3; // to track food and cuisines
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) { // T.C. O(n*log(n))
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            mp2[foods[i]] = ratings[i];
            mp3[foods[i]] = cuisines[i];
            mp1[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) { // T.C. O(n*log(n))
        // if(newRating > mp2[food]) {
            string c = mp3[food];
            
        // } else 
        stack<pair<int, string>> st;
        while(!mp1[c].empty() && mp1[c].top().second != food) {
            auto p = mp1[c].top();
            st.push({p.first, p.second});
            mp1[c].pop();
        }

        if(!mp1[c].empty() && mp2[food] != newRating) {
            mp1[c].pop();
            mp1[c].push({newRating, food});
        }

        while(!st.empty()) {
            mp1[c].push(st.top());
            st.pop();
        }
        mp2[food] = newRating;
    }
    
    string highestRated(string cuisine) { // T.C. O(n*log(n))
        stack<pair<int, string>> st;
        string ans = "";
        while(mp1[cuisine].size() > 1) {
            auto p1 = mp1[cuisine].top();
            st.push(p1);
            mp1[cuisine].pop();
            auto p2 = mp1[cuisine].top();

            if(p1.first == p2.first) {
                if(ans == "") ans = min(p1.second, p2.second);
                else ans = min(ans, min(p1.second, p2.second));
            } else {
                if(ans == "") ans = p1.second;
                else ans = min(ans, p1.second);
                break;
            }
        }

        if(st.empty()) return mp1[cuisine].top().second;

        while(!st.empty()) {
            mp1[cuisine].push(st.top());
            st.pop();
        }

        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */