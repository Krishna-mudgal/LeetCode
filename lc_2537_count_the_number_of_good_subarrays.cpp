#include <bits/stdc++.h>
using namespace std;

class Solution { // T.C. = O(n)
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            long long ans = 0;
            unordered_map<int, int> m;
            int i = 0, j = 1, x = 0;
            m[nums[i]]++;
            bool flag = false;
            while(i < j && j < n){
                
                if(m.find(nums[j]) == m.end()) m[nums[j]]++;
                else {
                    x += m[nums[j]];
                    m[nums[j]]++;
                    while(i < j && x >= k){ 
                        // i++ krne ke bad ab agr x>=k to isko bhi include krlo ni to ange j++ hoga map m nums[j] bhi add hojyga to jo agr i se lekar j ka subarray h and x >= k to yh wala subarray wo chuut jyega or isse jo bhi include ho rhe hoge wo bhi rh jyge (n - j itte subarray rh jyga agr condition true h to)
                        
                        ans += n - j;
                        m[nums[i]]--;
                        if(m[nums[i]] == 0) m.erase(nums[i]);
                        if(m.find(nums[i]) != m.end()) x -= m[nums[i]];
                        i++;
                    }
                }
    
                // cout << i << " " << j << " " << x << endl;
                
                j++;
            }
    
            while(i < j){
                if(x >= k) ans++;
                else break;
                x -= m[nums[i]]--;
                i++;
            }
    
            return ans;
        }
    };