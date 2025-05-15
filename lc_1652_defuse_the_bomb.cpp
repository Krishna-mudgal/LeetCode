#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n, 0);

        if(k == 0) return ans;
        else if(k > 0){
            int i = 0, j = 1;
            int sum = 0;
            while(j <= k) {
                sum += code[j];
                j++;
            }
            ans[i] = sum;
            i++;
            j = j % n;
            while(i < n){
                sum -= code[i];
                j = j % n;
                sum += code[j];
                ans[i] = sum;
                i++;
                j++;
                j = j % n;
            }
        }
        else {
            k = -k;
            int i = 0, j = n - 1;
            int sum = 0;
            while(j >= n - k){
                sum += code[j];
                j--;
            }
            ans[i] = sum;
            j++;
            while(i < n){
                sum += code[i];
                i++;
                sum -= code[j];
                j++;
                j = j % n;
                if(i == n) break;
                ans[i] = sum;
            }
        }

        return ans;

    }
};