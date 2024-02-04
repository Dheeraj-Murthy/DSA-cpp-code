#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n; cin >> n;
    for (long long int _=0; _<n; _++)
    {
        long long int num; cin >> num;
        vector<int>arr(num);
        for (long long int i = 0; i<num;i++) cin >> arr[i];long long int count = 0;
        vector<int>revarr(num);
        for (long long int i = 0; i < num; i++) revarr[arr[i]-1] = i;
        for (long long int i = 1; i < num; i++) if (revarr[i] < revarr[i-1])count++;
        cout << count << endl;
    }
}