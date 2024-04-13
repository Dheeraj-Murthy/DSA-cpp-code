#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cur(1001);
        for (auto trip: trips)
        {
            cur[trip[1]] += trip[0];
            cur[trip[2]] -= trip[0];
        }
        if (cur[0] > capacity) return false;
        for (int i = 1; i < 1001; i++){
            cur[i] += cur[i-1];
            if (cur[i] > capacity) return false;
        }
        return true;
    }
};