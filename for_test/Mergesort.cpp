#include<bits/stdc++.h>
using namespace std;

vector<int> Merge(vector<int>larr, vector<int>rarr)
{
    int n = larr.size(); int m = rarr.size();
    int i = 0, j = 0;
    vector<int>ans;
    while (i < n && j < m) {
        if (larr[i] < rarr[j]) ans.push_back(larr[i++]);
        else ans.push_back(rarr[j++]);
    }
    while(i < n) ans.push_back(larr[i++]);
    while(j < m) ans.push_back(rarr[j++]);
    return ans;
}

vector<int> MergeSort(vector<int>arr)
{
    int n = arr.size();
    if (n == 1) return arr;
    vector<int>larr; vector<int> rarr;
    for (int i = 0; i < n; i++)
    {
        if (i < n/2) larr.push_back(arr[i]);
        else rarr.push_back(arr[i]);
    }
    larr = MergeSort(larr);rarr = MergeSort(rarr);
    return Merge(larr, rarr);
}
int main()
{
    vector<int>arr;
    arr = {1, 3, 2, 7, 6, 5, 4};
    vector<int>ans(MergeSort(arr));
    for (int i:ans) cout << i << ' ';

}