#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/encode-and-decode-tinyurl/description/

class Solution {
public:
    unordered_map<string, string> m;
    int x = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s = to_string(x++);
        m[s] = longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));