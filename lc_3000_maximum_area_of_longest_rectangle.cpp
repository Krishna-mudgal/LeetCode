#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int ans = 0;
        long long longDiag = 0;
        for(int i = 0; i < n; i++) {
            int b = dimensions[i][1];
            int l = dimensions[i][0];
            long long diag = b*b + l*l;
            if(diag > longDiag) {
                ans = l*b;
                longDiag = diag;
            } else if(diag == longDiag)  ans = max(ans, (l*b));
        }

        return ans;
    }
};