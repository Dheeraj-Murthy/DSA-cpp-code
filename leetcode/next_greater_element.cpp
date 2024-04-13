#include<bits/stdc++.h>
using namespace std;

#include<stack>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int stack[nums2.size()]; int top = 0;
        stack[top++] = 0;
        int B[nums2.size()];
        vector<int>ans;
        
        for (int i = 1; i < nums2.size(); i++)
        {
            while(top > 0 && nums2[stack[top-1]] < nums2[i])
                B[stack[--top]] = i;
            stack[top++] = i; 
        }
        while(top>0) B[stack[--top]] = -1;
        //we got the next greater element of all elements of nums2
        
        int revindex[100000];
        for(int i = 0; i < nums2.size(); i++) revindex[nums2[i]] = i;
        //now to do the problem
        for (int i = 0; i < nums1.size(); i++){
            int temp = B[revindex[nums1[i]]];
            if (temp == -1) ans.push_back(-1);
            else ans.push_back(nums2[temp]);
        }
        return ans;
    }
};