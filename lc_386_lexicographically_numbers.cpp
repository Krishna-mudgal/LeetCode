#include <bits/stdc++.h>
using namespace std;

// bool cmp(int x, int y){
//     if(x > 9 && y > 9){
//         int a = x, b = y;
//         int fd_x, fd_y;

//         while(a >= 1){
//             fd_x = a%10;
//             a /= 10;
//         }

//         while(b >= 1){
//             fd_y = b%10;
//             b /= 10;
//         }

//         return fd_x < fd_y;
//     }
//     else if(x > 9){
//         int a = x;
//         int fd_x;

//         while(a >= 1){
//             fd_x = a % 10;
//             a /= 10;
//         }

//         return fd_x < y;
//     }
//     else if(y > 9){
//         int b = y;
//         int fd_y;
        
//         while(b >= 1){
//             fd_y = b % 10;
//             b /= 10;
//         }

//         return x < fd_y;
//     }
//     else return x < y;
// }

bool cmp(int x, int y){
    string a = to_string(x), b = to_string(y);

    return a < b;
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> v;
        for(int i = 1; i <= n ;i++) v.push_back(i);

        sort(v.begin(), v.end(), cmp);

        return v;

    }
};