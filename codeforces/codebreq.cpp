#include<bits/stdc++.h>
using namespace std;

long long int bs(vector<long long int>&arr, long long int start,long long int end,long long int num)
{
    if (start > end) return start;

    long long int mid = start + (end - start)/2;
    if (arr[mid] > num) return bs(arr, start, mid-1, num);
    else return bs(arr, mid+1, end, num);
}

int main()
{
    long long int n; cin >> n;
    vector<long long int>arr(n);
    for (long long int i_ = 0; i_ < n; i_++) cin >> arr[i_];
    sort(arr.begin(), arr.end());

    long long int q; cin>>q;
    for (int i_ = 0; i_ < q; i_++)
    {
        long long int m ; cin >> m;
        if (m >= arr[n-1]) 
        {
            cout << n << endl;
            continue;
        }
        cout << bs(arr, 0, n, m) << endl;

    }
}