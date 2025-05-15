#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        char ans = letters[0];

        sort(letters.begin(), letters.end());

        int i = 0;
        while(i < n){
            if(letters[i] > target) {
                ans = letters[i];
                break;
            }
            i++;
        }

        return ans;

    }
};

class Solution { // optimal approach
public:
    char nextGreatestLetter(vector<char>& letters, char target) { // using binary search
        int n = letters.size();
        char ans = letters[0];

        sort(letters.begin(), letters.end());

        int lo = 0, hi = n - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            if(letters[mid] > target){
                ans = letters[mid];
                hi = mid - 1;
            }
            else lo = mid + 1;

        }

        return ans;

    }
};