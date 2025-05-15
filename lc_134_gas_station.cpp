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