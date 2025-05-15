#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rabbits-in-forest/description/

class Solution {
public:
    int numRabbits(vector<int>& answers) { // optimisesd from previous solution

        int n = answers.size();

        unordered_map<int, int> m; // frequency map

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(m.find(answers[i]) == m.end()){
                ans += answers[i] + 1;   //  means this color of rabbit is different
            }
            m[answers[i]]++; // means this color is already counted
            if(m[answers[i]] == answers[i] + 1) m.erase(answers[i]); // means we found all rabbit of a group so eliminate this grp
            // for ex one rabbit says there are 4 more means there are total 5 rabbit of that color, so if frequency of answer 4 has become 5 then this means that particular varity of rabbits are over 
        }

        return ans;
        
    }
};


class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int n = answers.size();
            unordered_map<int, int> m;
            int ans = 0;
    
            for(int i = 0; i < n; i++){
                m[answers[i] + 1] += 1; // snswer[i] + 1 kyu ki answer[i] ke to aur h aur ek wo swayam
                if(m[answers[i] + 1] == answers[i] + 1) { // agr pure count hogye to inko hta hi do taki agli bar kisi ne 1 bola to wo alg consider ho
                    ans += answers[i] + 1;
                    m.erase(answers[i] + 1);
                }
            }
    
            for(auto p : m) ans += p.first;
    
            return ans;
        }
    };