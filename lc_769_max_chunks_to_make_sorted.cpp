#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int i = 0, ans = 1;
        int j = arr[i];

        // sort krne pr arr[i], arr[i]th index pr jyga
        // to suru wala jo element h let say 5 to sort krne pr wo 5th index pr jyga to ek chunk 5th index tk ka to ho hi gya aur agr 5th index ke bich m koi bda element milgya 5 se to phir range phir se bd jygi aur agr 5th index tk aise element mile jo ki 5 se km the to phir to range ni bdegi kyu ki 5th index tk agr sort krege to sare element apni correct position pr ajyge

        while(i < n){
            if(arr[i] <= j) i++;
            else {
                if(i - 1 == j) ans++;
                j = arr[i];
            }
        }

        return ans;
    }
};