#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long hours(const vector<int>& piles, int speed) {
        long long hrs = 0;
        for (int pile : piles) {
            // ceil(pile / speed) using integers
            hrs += (pile + speed - 1LL) / speed;
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long t = hours(piles, mid);

            if (t <= (long long)h) {
                ans = mid;        // mid works, try smaller
                high = mid - 1;
            } else {
                low = mid + 1;    // too slow, need bigger speed
            }
        }
        return ans;
    }
};
