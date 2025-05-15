#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int minSwaps(vector<int> &v){
        int ans = 0;
        vector<int> x(v.begin(), v.end());

        sort(x.begin(), x.end());
        unordered_map<int, int> m;
        for(int i = 0; i < x.size(); i++) m[x[i]] = i;
        
        
// agr sort position aur original position same ni h to unko swap krdo aur ans++ krdo aur jb tk dekhege tb tk us position pr uska correct element ni ajata tb tk yani ki jo original index h uspe jo element h jb tk wo ni ata tb tk, adjacent swap krne ki koi jrurt ni h direct krdo swap, aur reality m swap krna jruri h kyu ki last wale element apne aap right position pr phuch jyge end m to agr ni krege to unke swap bhi count krne pdege

        int i = 0;
        while(i < v.size()){
            int c_idx = m[v[i]];
            if(c_idx != i){
                swap(v[c_idx], v[i]);
                ans++;
            }
            else i++;
        }

        return ans;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        
        int ans = 0;
        vector<int> v;
        while(q.size() > 0){
            int n = q.size();
            v.resize(0);
            for(int i = 0; i < n; i++){
                auto t = q.front();
                q.pop();

                v.push_back(t -> val);

                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }

            ans += minSwaps(v);
        }

        return ans;

    }
};