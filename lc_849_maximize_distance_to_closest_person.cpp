#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximize-distance-to-closest-person/description/


class Solution { // T.C. = O(n^2)
    public:
        int maxDistToClosest(vector<int>& seats) {
            int n = seats.size();
    
            int ans = 0;
            for(int i = 0; i < n; i++){
                if(seats[i] == 0){
                    int a = i - 1;
                    int cnt1 = 0, cnt2 = 0;
                    while(a >= 0){
                        cnt1++;
                        if(seats[a] == 1) break;
    
                        a--;
                    }
                    bool flag = false;
                    if(a == -1 && seats[a + 1] == 0) flag = true;
                    a = i + 1;
                    while(a < n){
                        cnt2++;
                        if(seats[a] == 1) break;
    
                        a++;
                    }
    
                    int x;
                    if((a == n && seats[a - 1] == 0) || flag) {
                        x = max(cnt1, cnt2);
                    }
                    else x = min(cnt1, cnt2);
    
                    ans = max(ans, x);
                }
            }
    
            return ans;
        }
    };