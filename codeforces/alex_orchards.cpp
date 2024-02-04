#include<bits/stdc++.h>
using namespace std;

long long int time(vector<long long int>arr, long long int speed)
{
    int time = 0;
    for (auto it:arr)
    {
        time += (it +speed -1 )/speed;
    }
    // cout << speed << ',' << time << '\n';
    return time;
}

long long int bs(vector<long long int>arr, long long int start, long long int end, long long int limit)
{
    if (start > end) return start;
    // cout << start << '-' << end << endl;
    

    long long int mid = start + (end - start)/2;
    long long int mid_time = time(arr, mid);

    if (mid_time <= limit) return bs(arr, start, mid-1, limit);
    else return bs(arr, mid+1, end, limit);
}

int main()
{
    long long int n, h; cin >> n >> h;
    if (n > h){ 
        cout << -1;
        return 0;
    }
    vector<long long int>arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    auto maxi = max_element(arr.begin(), arr.end());
    cout << bs(arr, 0, *maxi, h);

}