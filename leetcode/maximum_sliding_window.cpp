#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    deque<int> window;
    vector<int> ans;
    int i = 0;
    while (i < nums.size()) 
    {
        if (!window.empty() && window.front() == i - k) window.pop_front();
        
        while (!window.empty() && nums[window.back()] < nums[i]) window.pop_back();
        window.push_back(i);

        if (i >= k-1)
            ans.push_back(nums[window.front()]);
        i++;
        // for (auto i:window) cout << i << ' '; cout << endl;
    }
    return ans;
}