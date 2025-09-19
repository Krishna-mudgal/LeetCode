#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-spreadsheet/description/?envType=daily-question&envId=2025-09-19

// more optimized :
class Spreadsheet {
public:
    unordered_map<string, int> mp;
    Spreadsheet(int rows) { // T.C. = O(1)
        
    }
    
    void setCell(string cell, int value) { // T.C. = O(1)
        mp[cell] = value;
    }
    
    void resetCell(string cell) { // T.C. = O(1)
        mp[cell]  = 0;
    }
    
    int getValue(string formula) { // T.C. = O(n), n = formula.size();
        string a = "", b = "";
        int i = 1;
        while(i < formula.size()) {
            bool flag = false;
            if(a.size() == 0) flag = true;
            while(i < formula.size() && formula[i] != '+') {
                if(flag) a += formula[i];
                else b += formula[i];
                i++;
            }
            i++;
        }

        int val1 = 0;
        if(a[0] >= 'A' && a[0] <= 'Z') {
            val1 = mp[a];
        } else {
            val1 = stoi(a);
        }

        int val2 = 0;
        if(b[0] >= 'A' && b[0] <= 'Z') {
            val2 = mp[b];
        } else {
            val2 = stoi(b);
        }

        return val1 + val2;
    }
};

// ------------------------------------------------------------------------------------

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) { // T.C. = O(rows)
        v.resize(rows, vector<int> (27, 0));
    }
    
    void setCell(string cell, int value) { // T.C. = O(n), n=cell.size();
        int c = cell[0]-'A';
        int r = stoi(cell.substr(1)) - 1;
        v[r][c] = value;
    }
    
    void resetCell(string cell) { // // T.C. = O(n), n=cell.size();
        int c = cell[0]-'A';
        int r = stoi(cell.substr(1)) - 1;
        v[r][c] = 0;
    }
    
    int getValue(string formula) { // // T.C. = O(n), n=formula.size();
        string a = "", b = "";
        int i = 1;
        while(i < formula.size()) {
            bool flag = false;
            if(a.size() == 0) flag = true;
            while(i < formula.size() && formula[i] != '+') {
                if(flag) a += formula[i];
                else b += formula[i];
                i++;
            }
            i++;
        }

        int val1 = 0;
        if(a[0] >= 'A' && a[0] <= 'Z') {
            int r1 = stoi(a.substr(1)) - 1;
            int c1 = a[0] - 'A';
            val1 = v[r1][c1];
        } else {
            val1 = stoi(a);
        }

        int val2 = 0;
        if(b[0] >= 'A' && b[0] <= 'Z') {
            int r1 = stoi(b.substr(1)) - 1;
            int c1 = b[0] - 'A';
            val2 = v[r1][c1];
        } else {
            val2 = stoi(b);
        }

        return val1 + val2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */