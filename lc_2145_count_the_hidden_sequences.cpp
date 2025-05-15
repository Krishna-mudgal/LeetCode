#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=jmpUP1MaQ9Q

class Solution {
    public:
    
        bool check_1(vector<int> &differences, long long x, int &upper){
            for(auto i : differences) {
                x += i;
                if(x > upper) return false;
            }
    
            return true;
        }
    
        bool check_2(vector<int> &differences, long long x, int &lower){
            for(auto i : differences) {
                x += i;
                if(x < lower) return false;
            }
    
            return true;
        }
    
        int numberOfArrays(vector<int>& differences, int lower, int upper) { // T.C. = O(n*log(upper - lower))
            int n = differences.size();
            
            int lo = lower, hi = upper;
            long long upper_range = LLONG_MAX, lower_range = LLONG_MAX;
            // here we are calculating highest possible value between lower and upper for which we get all values after applying differences less than or equal to upper (here we are considering only upper)
            while(lo <= hi){
                long long mid = lo + (hi - lo)/2;
                
                if(check_1(differences, mid, upper)) {
                    upper_range = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
    
            }
    
            if(upper_range == LLONG_MAX) return 0;
    
            lo = lower, hi = upper;
            // here we are calculating lowest possible value between lower and upper for which we get all values after applying differences greater than or equal to lower (here we are considering only lower)
            while(lo <= hi){
                long long mid = lo + (hi - lo)/2;
    
                if(check_2(differences, mid, lower)){
                    lower_range = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
    
            if(lower_range == LLONG_MAX) return 0;
    
            // ans would be all values that lie between [lower_range, upper_range]
            return (upper_range - lower_range + 1 < 0) ? 0 : (upper_range - lower_range + 1) ;
    
        }
    };