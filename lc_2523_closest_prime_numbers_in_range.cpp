#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07

class Solution {
    public:
    
        bool check(int n){
            for(int i = 2; i <= sqrt(n); i++){
                if(n % i == 0) return false;
            }
    
            return true;
        }
    
        vector<int> closestPrimes(int left, int right) {
            // T.C. = O(n*sqrt(n))
    
            vector<int> v;
            if(left == 1) left++;
            for(int i = left; i <= right; i++){
                if(check(i)) v.push_back(i);
            }
    
            vector<int> ans = {-1, -1};
            if(v.size() < 2) return ans;
            int difference = INT_MAX;
            for(int i = 0; i < v.size() - 1; i++){
                if(v[i + 1] - v[i] < difference) {
                    difference = v[i + 1] - v[i];
                    ans = {v[i], v[i + 1]};
                    if(difference <= 2) return ans;
                }
            }
    
            return ans;
        }
    };

    class Solution { // T.C. = O(n*log(log(n)))
        public:
            vector<int> closestPrimes(int left, int right) {
                // In this approach, I have used Sieve of Eratosthenes
                // previously T.C. was O(n*sqrt(n))
                int n = right - left;
                if(n == 0) return {-1, -1};
        
                vector<bool> v(right + 1, true);
                v[0] = false;
                v[1] = false;
        
                for(int i = 2; i < sqrt(v.size()); i++){
                    if(v[i]){
                        int j = 2;
                        while(true){
                            if(i*j > v.size()) break;
                            else v[i*j] = false; // prime number ke multiples ko false mark krdo
        
                            j++;
                        }
                    }
                }
        
                vector<int> ans = {-1, -1};
                int diff = INT_MAX;
                int i = left, j = left;
                while(i < v.size() && !v[i]) i++;
                j = i + 1;
                while(j < v.size() && !v[j]) j++;
                
                if(j >= v.size()) return ans;
                diff = j - i;
                ans = {i, j};
                if(diff <= 2) return ans;
                
                while(j < v.size()){
                    i = j;
                    j++;
                    while(j < v.size() && !v[j]) j++;
                    
                    if(j == v.size()) return ans;
        
                    if(diff > j - i) {
                        diff = j - i;
                        ans = {i, j};
        
                        if(diff <= 2) return ans;
                    }
                } 
        
                return ans;
            }
        };