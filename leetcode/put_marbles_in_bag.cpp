#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long mx = 0,mn = 0;
        int n = weights.size();
        vector<long long int>pairsums;
        for (int i = 1; i < n; i++)
            pairsums.push_back(weights[i]+weights[i-1]);
        sort(pairsums.begin(), pairsums.end());
        for (int i = 0; i < k-1; i++){
            mn += pairsums[i];
            mx += pairsums[n-2-i];
        }
        long long ans = mx - mn;
        return ans;
    }
};