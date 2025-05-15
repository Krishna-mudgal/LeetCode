#include <bits/stdc++.h>
using namespace std;

class Solution { // approach - 1
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();

        sort(maximumHeight.begin(), maximumHeight.end());
        unordered_map<int, int> m;

        long long ans = maximumHeight[0];
        long long last_added = maximumHeight[0];
        m[maximumHeight[0]]++;

        for(int i = 1; i < n; i++){
            
            int x;
            if(maximumHeight[i] == maximumHeight[i - 1]){
                x = last_added - 1;
            }
            else x = maximumHeight[i];
            
            while(x > 0){
                if(m.find(x) == m.end()){
                    ans += x;
                    last_added = x;
                    m[x]++;
                    break;
                }
                x--;
            }

            if(x == 0) return -1;

        }

        return ans;

    }
};

class Solution { // approach - 2, using hints
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();

        sort(maximumHeight.begin(), maximumHeight.end());
        long long ans = maximumHeight[n - 1];

        for(int i = n - 2; i >= 0; i--){
            
            maximumHeight[i] = min(maximumHeight[i], maximumHeight[i + 1] - 1);

            if(maximumHeight[i] < 1) return -1;

            ans += maximumHeight[i];

        }

        return ans;

    }
};