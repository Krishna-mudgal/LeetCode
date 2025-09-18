#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/design-task-manager/description/?envType=daily-question&envId=2025-09-18

class TaskManager { // similar to lc_2353
public:
    unordered_map<int, int> mp1, mp2; // 1 for taskId, userId and 2 for taskId, priority of that task
    set<pair<int, int>> st;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++)  {
            mp1[tasks[i][1]] = tasks[i][0];
            mp2[tasks[i][1]] = tasks[i][2];
            st.insert({-1*tasks[i][2], -1*tasks[i][1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp1[taskId] = userId;
        mp2[taskId] = priority;
        st.insert({-1*priority, -1*taskId});
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = mp2[taskId];
        st.erase({-1*oldPriority, -1*taskId});
        st.insert({-1*newPriority, -1*taskId});
        mp2[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        int priority = mp2[taskId];
        st.erase({-1*priority, -1*taskId});
        mp1.erase(taskId);
        mp2.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        
        int taskId = -1*(st.begin() -> second);
        int userId = mp1[taskId];
        int priority = mp2[taskId];
        st.erase({-1*priority, -1*taskId});
        mp1.erase(taskId);
        mp2.erase(taskId);

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */