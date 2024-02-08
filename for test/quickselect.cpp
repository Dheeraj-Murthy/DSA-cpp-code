//this code basically finds the kth largest element in an array

#include<bits/stdc++.h>
using namespace std;


int Partition(vector<int>&arr, int l, int r)
{
    int i = l+1; int j = r;
    while (i <= j)
    {
        while (i <= j && arr[i] <= arr[l]) i++;
        while (i <= j && arr[j] >  arr[l]) j--;
        if (i <= j) swap(arr[i], arr[j]);
        i++; j--;
    }
    swap(arr[i-1], arr[l]);
    return i-1;
}

int quickselect(vector<int>&arr, int l, int r, int k)
{
    if (l > r) return l;
    int p = (rand()%(r-l+1)) + l;
    swap(arr[l],arr[p]);
    p = Partition(arr, l, r);
    if (k == p) return k;
    if (k < p) return quickselect(arr, l, p-1, k);
    else return quickselect(arr, p+1, r, k);
}

int main()
{
    int n, k; cin >> n >> k;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = quickselect(arr, 0, n-1, n-k+1);
    cout << arr[ans] << ' ' << ans; 
}