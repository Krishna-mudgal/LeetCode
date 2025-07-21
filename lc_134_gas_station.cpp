#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/gas-station/

// greedy yt se dekhi thi

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // optimized with gready

        int n = gas.size();

        long long total_expense = 0, total_income = 0;
        for(int i = 0; i < n; i++){
            total_expense += cost[i];
            total_income += gas[i];
        }

        if(total_expense > total_income) return -1;

        int total = 0, ans = 0;
        for(int i = 0; i < n; i++){
            total += gas[i] -  cost[i];
            if(total < 0){
                ans = i + 1;
                total = 0;
            }
        }
        
        return ans;
        
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { // brute force
        int n = gas.size();

        for(int i = 0; i < n; i++){
            int c_gas = 0;
            bool flag = false;
            for(int j = i; j < n; j = (j + 1) % n){
                c_gas += gas[j];
                int c_cost = cost[j];
                if(flag && j == i) return i;
                flag = true;
                if(c_gas >= c_cost){
                    c_gas -= c_cost;
                }
                else break;
            }
        }

        return -1;

    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int cgas = 0;
        int i = 0;
        bool haveStarted = false;
        int start = 0;
        int ans = -1;
        int cnt = 0;
        while(i < n){
            if(i == start && haveStarted) {
                ans = start;
                break;
            }
            else if(i == start) haveStarted = true;

            if(cnt > 2*n) return -1;

            cgas += gas[i];
            if(cost[i] > cgas) {
                i++;
                i %= n;
                start = i;
                haveStarted = false;
                cgas = 0;
                // cnt = 0;
            }
            else {
                cgas -= cost[i];
                i++;
                i %= n;
            }
            cnt++;

        }

        return ans;

    }
};