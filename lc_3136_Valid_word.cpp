#include <bits/stdc++.h>
using namespace std;

class Solution { // T.C. = O(n)
public:

    bool helper(char c){
        if(c - '0' >= 0 && c - '0' <= 9) return true;
        else if(c >= 'a' && c <= 'z') return true;
        else if(c >= 'A' && c <= 'Z') return true;
        else return false;
    }

    bool isValid(string word) {
        int n = word.size();
        if(n < 3) return false;
        bool vowel = false;
        bool consonant = false;

        for(auto c : word){
            if(helper(c)) {
                if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') vowel = true;
                else if(c - '0' >= 0 && c - '0' <= 9) continue;
                else consonant = true;
            }
            else return false;
        }

        return (vowel && consonant);
    }
};