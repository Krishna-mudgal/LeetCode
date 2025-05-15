#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/fruit-into-baskets/

class Solution { // T.C = O(n)
public:
    int totalFruit(vector<int>& fruits) { // similar to max sum of subarray with k unique element
        int n = fruits.size();

        unordered_map<int, int> m;
        int ans = 0;

        int i = 0, j = 0;

        while(j < n){
            if(m.size() < 3){ // green flag(jb tk 2 hi variety ke fruits a rhe h to unko lete jao)
                m[fruits[j]]++;
                j++;
            }
            if(m.size() == 3){ // means red flag (map m ab 3 variety ke fruits hai) -> limite excided
                while(m.size() > 2){ // jb tk map ka size wapis 2 ni hojata tb tk i ko bdao aur us ith element ko map se hta do aur agr uski freq 0 ho jaye latest htane ke baad to usko erase bhi krdo
                    m[fruits[i]]--;
                    if(m[fruits[i]] == 0) m.erase(fruits[i]);
                    i++;
                }
            }

            ans = max(ans, j - i);
        }

        return ans;

    }
};