#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    unordered_map<int,int>mpp;
    vector<int>ans;
    for (int i = 1; i <= n; i++){
        int t; cin >> t;
        mpp[t] = i;
    }
    int temp = mpp[-1];
    while (temp != 0){
        ans.push_back(temp);
        temp = mpp[ans.back()];
    }
    for (int it:ans) cout << it << ' ';
}