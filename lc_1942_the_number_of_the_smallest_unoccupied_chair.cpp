#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11

class Solution { // brute force
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chair = 0;
        int n = times.size();

        targetFriend = times[targetFriend][0];

        sort(times.begin(), times.end());
        vector<int> v(n, -1);

        int i = 0;
        while(i < n){
            int arrival = times[i][0];
            int departure = times[i][1];

            for(int j = 0; j < n; j++){
                if(v[j] <= arrival){
                    if(arrival == targetFriend) return j;
                    else v[j] = departure;
                    break;
                }
            }

            i++;
        }

        return -1;
    }
};

class Solution { // optimum
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int chair = 0;
        int n = times.size();

        targetFriend = times[targetFriend][0];

        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;//{depature time, chair_number}  // to manage departure times (thorugh this we will get minimum departure time)

        priority_queue<int, vector<int> , greater<int> > pq2; //(free_chair_number) // to manage free chairs (since we have to always select chair with minimum number so using pq2)

        if(times[0][0] == targetFriend) return 0;

        int i = 0;
        while(i < n){
            
            // is condition kr hr br dekhlo yhi glti ho rhi thi bar bar
            
            // chair free jitni bhi ho rhi h current scenario se phle unko free krwado aur pq2 m push krwa do so that we will get minimum freeid chair's number for present or in future also
            while(!pq.empty() && times[i][0] >= pq.top().first){
                pq2.push(pq.top().second);
                pq.pop();
            }

            if(pq.empty() || times[i][0] < pq.top().first){ 
                if(!pq2.empty()){ // if there are already free chairs available then select from them and push it to pq
                    int x = pq2.top();
                    pq2.pop();
                    if(times[i][0] == targetFriend) return x;
                    pq.push({times[i][1], x});
                }
                else{ // if no free chair then assign new chair and push it to pq
                    if(times[i][0] == targetFriend) return chair;
                    pq.push({times[i][1], chair});
                    chair++;
                }
            }
            else { // if(times[i][0] >= pq.top().first)

                // pq2 pkka mai free chairs hogi tbhi apn yha pr ayye h kyu ki agr times[i][0] >= pq.top().first to upr loop m pq2 m free chair dal gyi hogi
                int x = pq2.top();
                pq2.pop();
                if(times[i][0] == targetFriend) return x;
                pq.push({times[i][1], x});
            }
            i++;
        }

        return -1;
    }
};