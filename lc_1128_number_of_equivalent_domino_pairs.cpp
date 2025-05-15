#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04

class Solution { // T.C. = O(n*log(n))
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int n = dominoes.size();
    
            for (auto& d : dominoes) if (d[0] > d[1]) swap(d[0], d[1]); // to handle test case : [[1, 3], [1, 2], [2, 1]] => if you don't swap them then after sort result will be [[1, 2], [1, 3], [2, 1]] and ans will 0 but ans is 1 bcs [1, 2] == [2, 1], so you need to first swap those dominoes whose d[0] > d[1] so that after sorting they will come close 
    
            sort(dominoes.begin(), dominoes.end());
    
            int ans = 0;
            int cnt = 1;
            for(int i = 0; i < n - 1; i++){
                if((dominoes[i][0] == dominoes[i + 1][0] && dominoes[i][1] == dominoes[i + 1][1]) || (dominoes[i][1] == dominoes[i + 1][0] && dominoes[i][0] == dominoes[i + 1][1])) {
                    ans += cnt;
                    cnt++;
                }
                else cnt = 1;
            }
    
            return ans;
        }
    };
    

    class Solution { // T.C. = O(45*n) = O(n)
        public:
            int numEquivDominoPairs(vector<vector<int>>& dominoes) {
                int n = dominoes.size();
                
                int ans = 0;
                vector<pair<vector<int>, int>> v;
        
                for(int i = 0; i < n; i++){
                    bool flag = true;
                    int a = dominoes[i][0], b = dominoes[i][1];
                    for(int j = 0; j < v.size(); j++){
                        int c = v[j].first[0], d = v[j].first[1];
                        if((a == c && b == d) || (a == d && b == c)) {
                            ans += v[j].second;
                            v[j].second++;
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag) v.push_back({{a, b}, 1});
                }
                
                return ans;
            }
        };


// int main(){
//     vector<pair<vector<int>, int>> p;

//     p.push_back({{1, 2}, 1});
//     p.push_back({{3, 4}, 1});

//     for(int i = 0; i < p.size(); i++){
//         cout << p[i].first[0] << p[i].first[1] << p[i].second << endl;
//     }
// }