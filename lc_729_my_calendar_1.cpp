#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26

class MyCalendar { // my approach
public:
    vector<pair<int, int> > v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.size() == 0) {
            v.push_back({start, end});
            return true;
        }
        else{
            for(auto p : v){
                // conflict cases (if(first == start) -> conflict, if(first == end) -> no conflict, if(second == start) -> no conflict, if(second == start) -> no conflict)
                if(p.first <= start && p.second >= end) return false;
                else if(p.first >= start && p.second > end && start < p.second && end > p.first) return false; 
                else if(p.first <= start && end > p.second && start < p.second && end > p.first) return false;
                else if(p.first >= start && p.second <= end && p.second > start && p.first < end) return false;
            }
            v.push_back({start, end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

class MyCalendar { // 2nd approach
public:
    vector<pair<int, int> > v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(v.size() == 0) {
            v.push_back({start, end});
            return true;
        }
        else{
            for(auto p : v){
                if(p.second > start && p.first < end) return false; // there is a conflict
            }
            v.push_back({start, end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */