#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/restore-ip-addresses/description/

class Solution {
    public:
        
        string check(string &s, int &i, int &j, int &k){
            string one = s.substr(0, i);
            string sec = s.substr(i, j - i);
            string third = s.substr(j, k - j);
            string fourth = s.substr(k);
    
            // if size of any string is > 3 then this means for sure this number is > 255 
            if((one[0] == '0' && one.size() > 1) || one.size() > 3 || stoi(one) > 255) return "1";
            else if((sec[0] == '0' && sec.size() > 1) || sec.size() > 3 || stoi(sec) > 255) return "2";
            else if((third[0] == '0' && third.size() > 1) || third.size() > 3 || stoi(third) > 255) return "3";
            else if((fourth[0] == '0' && fourth.size() > 1) || fourth.size() > 3 || stoi(fourth) > 255) return "4";
            else return (one + '.' + sec + '.' + third + '.' + fourth);
        }
    
        vector<string> restoreIpAddresses(string s) { // T.C. = O(n^3)  
            int n = s.size();
            if(n > 12) return {};
    
            vector<string> ans;
    
            for(int i = 1; i < n - 2; i++){
                string result = "";
                for(int j = i + 1; j < n - 1; j++){
                    result = "";
                    for(int k = j + 1; k < n; k++){
                        result = check(s, i, j, k);
                        if(result == "1" || result == "2" || result == "3") break; // if mistake is in 4 then as we move forward 4 is going to decrease and if mistake is in 1 or 2 or 3 then there is no point of making any adjustment in 4 so break
                        else if(result != "4") ans.push_back(result);
                    }
                    if(result == "1" || result == "2") break; // if mistake is in 3 then as we move forward in this lope, size of 3 is going to decrease so we can still check for next iterations but if mistake is in 1 or 2 then there is no point of moving forward because we are not manipulating 1 or 2 here
                }
                if(result == "1") break; // if mistake is in 2 then as we move forward in this lope, size of 2 is going to decrease so we can still check for next iterations but if mistake was in 1 then there is no point of moving forward because as we move forward size of 1 is going to increase
            }
    
            return ans;
        }
    };