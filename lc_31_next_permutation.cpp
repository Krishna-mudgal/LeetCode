#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) { // T.C. = O(n)
        int n = nums.size();

        // aisa place dekho jha pr nums[i] < nums[i + 1] iska mtlv sequence kch 1543 where i is pointing to 1 types h to isme i+1 se end tk already maximum hai apn usme next greater ni kr skte pr 1543 m krskte hai to phir isko krne ke liye apn ko 1 ko just greater than 1 se swap krna pdega or baki ka sort kerke add krdo i ke baad se

        // 4325413 isme 5413 already max h to apn i ko 2 pr le jyge 
        // ab i se just bda dekho end tk to wo 3 milega
        // ab 2 or 3 ko swap krdo to number hojyga -> 4335412
        // ab i ke baad ka sort kro to wo hoga -> 5421
        // ab i ke baad isko lga do or purana hta do -> 4335421 or return krdo

        bool flag = false;
        vector<int> v = nums;
        string s = "";
        s += nums[n - 1] + '0';
        v.pop_back();
        int x = INT_MAX, idx = -1;
        int i = n - 2;
        while(i >= 0){
            if(v[i] < v[i + 1]){
                for(int j = 0; j < s.size(); j++){
                    if(v[i] < (s[j] - '0') && x > (s[j] - '0')) {
                        x = s[j] - '0';
                        idx = j;
                    }
                }

                int a = s[idx] - '0';
                swap(s[idx], s[s.size() - 1]);
                s.pop_back();
                s += (v[i] + '0');
                swap(s[idx], s[s.size() - 1]);
                v[i] = a;
                sort(s.begin(), s.end());

                for(auto c : s) v.push_back(c - '0');

                nums = v;
                return ;

            }

            s += (v[i] + '0');
            i--;
            v.pop_back();
        }

        reverse(nums.begin(), nums.end());

    }
};