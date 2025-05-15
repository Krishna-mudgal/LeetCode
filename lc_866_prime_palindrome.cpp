#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/prime-palindrome/

class Solution {
    public:
        bool isprime(long long n) {
            if(n < 2) return false;
            if(n == 2) return true;
            if(n % 2 == 0) return false;
    
            for(long long i = 3; i<= sqrt(n); i += 2){
                if(n % i == 0) return false;
            }
            return true;
        }
    
        bool ispalindrome(long long n){
            string s = to_string(n);
            int i = 0, j = s.size() - 1;
            while(i <= j) {
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
    
            return true;
        }
        int primePalindrome(int n) {
    
            for(long long i = n; i <= 100030001; i++){
                if(i >= 9989900) return 100030001;
                if(isprime(i) && ispalindrome(i)) return i;
            }
    
            return -1;
        }
    };