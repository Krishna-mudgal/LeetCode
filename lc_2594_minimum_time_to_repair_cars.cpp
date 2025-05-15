#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

class Solution {
    public:
    
        // This is minimize the maximum problem because we have to minimize the maximum time taken by a mechanic
    
        // time = rank * cars^2
        // therefore cars = sqrt(time/rank) , this gives if time is given then how many cars a meachanic with rank r can repair (agr time 100 h aur mechanic ki 2 to wo 5 car repair kr skta h)
        // then at end check if toatal cars that can be repaired in given time is >= total_cars or not
    
        int n;
    
        bool check(vector<int> &ranks, long long &time, int &cars){
            vector<long long> car_taken(n);
    
            for(int i = 0; i < n; i++) {
                car_taken[i] = sqrt(time/ranks[i]);
            }
    
            long long x = 0;
            for(auto i : car_taken){
                x += i;
            }
    
            return x >= cars;
        }
    
        long long repairCars(vector<int>& ranks, int cars) { // T.C. = O(n * log(LLONG_MAX)) == O(n)
            n = ranks.size();
    
            int max_rank = *max_element(ranks.begin(), ranks.end());
            long long lo = 1, hi = LLONG_MAX; // hi = max_rank*cars*cars but this is exceeding long long limit and ans was in long long so max ans would be LLONG_MAX that is why hi is initialized with LLONG_MAX
            long long ans = LLONG_MAX;
    
            while(lo <= hi){ // T.C. = O(log(LLONG_MAX))
                long long mid = lo + (hi - lo)/2;
    
                if(check(ranks, mid, cars)){ // T.C. = O(n) without considering time complexity of sqrt
                    ans = min(ans, mid);
                    hi = mid - 1;
                }
                else lo = mid + 1;
    
            }
    
            return ans;
    
        }
    };