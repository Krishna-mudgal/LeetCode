#include <bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/guess-number-higher-or-lower/description/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

// class Solution {
// public:
//     int guessNumber(int n) {
//         int i = 1, j = n;

//         while(i <= j){
//             int mid = i + (j - i)/2;

//             int x = guess(mid);

//             if(x == 0) return mid;
//             else if(x == -1) j = mid - 1;
//             else i = mid + 1;

//         }

//         return -1;
//     }
// };