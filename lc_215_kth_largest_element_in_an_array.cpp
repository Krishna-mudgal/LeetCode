#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution { // using priority queue, T.C. = O(n*log(n))
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int &i : nums) pq.push(i);

        while(k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};

class Solution { // using sorting algorithm, T.C. = O(n*log(n))
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


class Solution { // using merge sort
public:

    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        int n = v1.size(), m = v2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while(i < n || j < m) {
            if(i == n) ans.push_back(v2[j++]);
            else if(j == m) ans.push_back(v1[i++]);
            else if(v1[i] > v2[j]) ans.push_back(v2[j++]);
            else ans.push_back(v1[i++]);
        }
        
        return ans;
    }

    void mergeSort(vector<int> &nums) {
        int n = nums.size();
        if(n == 1) return;
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < n; i++) {
            if(i < n/2) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }

        mergeSort(v1);
        mergeSort(v2);

        nums = merge(v1, v2);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        mergeSort(nums);

        return nums[n - k];
    }
};

class Solution { // using quickSort but getting T.L.E in this
public:

    void quickSort(vector<int> &nums, int lo, int hi) {
        if(lo >= hi) return;

        int idx = lo + (hi - lo)/2;
        int correct_index = lo;
        for(int i = lo; i <= hi; i++) {
            if(nums[i] < nums[idx]) correct_index++;
        }

        swap(nums[correct_index], nums[idx]);

        int i = correct_index - 1, j = correct_index + 1;
        while(i >= lo && j <= hi) {
            if(nums[i] < nums[correct_index]) i--;
            else if(nums[j] >= nums[correct_index]) j++;
            else if(nums[i] >= nums[correct_index] && nums[j] < nums[correct_index]) swap(nums[i--], nums[j++]);
        }

        quickSort(nums, lo, correct_index - 1);
        quickSort(nums, correct_index + 1, hi);

    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        quickSort(nums, 0, n - 1);
        // for(int i : nums) cout << i << " ";

        return nums[n - k];
    }
};