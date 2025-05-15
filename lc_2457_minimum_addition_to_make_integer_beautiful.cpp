#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/

class Solution {
public:
    
    bool check(long long &n, int &target){
        string x = to_string(n);

        int a = 0;
        for(int i = 0; i < x.size(); i++){
            a += (x[i] - '0');
        }

        if(a <= target) return true;
        else return false;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long ans = 0;

        while(true){
            if(check(n, target)) return ans;
            else{
                string x = to_string(n);
                int i = x.size() - 1;
                while(i >= 0){
                    if(x[i] != '0'){
                        if(i == 0){ // puri new string of size x.size() + 1, jisme 0th index pr 1 hoga aur baki sb 0 hoga
                            string s = "1";
                            for(int i = 0; i < x.size(); i++) s += '0';

                            ans += (stoll(s) - n);
                            n = stoll(s);
                            break;
                        }
                        else{ // ith digit pr 0 lado to overall sum minus hojyga
                            
                            long long a = (10 - (x[i] - '0'));
                            
                            for(int j = i + 1; j < x.size(); j++){
                                a *= 10;
                            }

                            ans += a;
                            n += a;
                            break;
                        }
                    }
                    else i--;
                }
            }
        }

        return ans;

    }
};