#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size() == 0) {
            pq1.push(num);
            return;
        }

        if(num >= pq1.top()) pq2.push(num);
        else pq1.push(num);

        // agr max m heap m km element h agr min heap se to max heap m daal do aur agr max heap m min heap m jitne element h usse 1 se jada element h to phir min heap m daalo
        // dono ka size equal h to ok ya size of max heap - size of min heap == 1 to ok

        if(pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
        else if(pq1.size() - pq2.size() > 1){
            pq2.push(pq1.top());
            pq1.pop();
        }
    }
    
    double findMedian() {
        if(pq1.size() == pq2.size()){
            return (pq1.top() + pq2.top())/2.0;
        }
        else return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */