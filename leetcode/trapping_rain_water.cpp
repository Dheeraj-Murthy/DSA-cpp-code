#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lmax(n), rmax(n);
        lmax[0] = 0; rmax[n-1]=0;
        int ans = 0;
        for (int i = 1; i < n-1; i++)
            lmax[i] = max(lmax[i-1],height[i-1]);
        for (int i = n-2; i > -1; i--)
            rmax[i] = max(rmax[i+1],height[i+1]);
        for (int i = 0; i < n; i++)
        {
            ans += max(min(lmax[i],rmax[i]) - height[i],0);
        }
        return ans;
    }
};