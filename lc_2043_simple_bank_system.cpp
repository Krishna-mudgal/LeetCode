#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26

class Bank {
public:
    vector<long long> v;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size();
        v = move(balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || v[account1 - 1] < money) return false;

        v[account2 - 1] += money;
        v[account1 - 1] -= money;

        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n) return false;
        v[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || v[account - 1] < money) return false;
        v[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */