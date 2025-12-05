#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        int i = 0, j = n - 1;
        while(i < n && directions[i] == 'L') i++; // skip first set of cars moving in left because they will never collide
        while(j >= 0 && directions[j] == 'R') j--; // skip last set of cars moving in right because they will never collide
        while(i <= j) {
            if(directions[i] != 'S') ans++; // only L and R can cause any collisions because stationary itself can't collide with any car, it will get collided by a left or right moving car
            i++;
        }

        return ans;
    }
};

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        stack<char> st;
        int ans = 0;
        for(char c : directions) {
            if(st.empty()){
                if(c != 'L') st.push(c);
            } 
            else if(c == 'L' && st.top() == 'R') {
                ans += 2;
                st.pop();
                while(!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            }
            else if(c == 'L' && st.top() == 'S') {
                ans++;
                st.pop();
                while(!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            }
            else if(c == 'S' && st.top() == 'R') {
                ans++;
                st.pop();
                while(!st.empty() && st.top() == 'R') {
                    ans++;
                    st.pop();
                }
                st.push('S');
            } else if(c == 'R' && st.top() == 'S') {
                st.push(c);
            } else if(c == 'R' && st.top() == 'R') st.push(c);
        }

        return ans;
    }
};