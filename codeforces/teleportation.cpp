#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int num_query; cin >> num_query;
    for (long long int i = 0; i < num_query; i++)
    {
        long long int n, c; cin >> n >> c;
        vector<long long int> arr(n);
        for (long long int j = 0; j < n; j++){
            cin >> arr[j];
            arr[j] += j+1;
        }
        sort(arr.begin(), arr.end());
        long long int j = 0;
        for( ; j < arr.size(); j++) {     
            c -= arr[j];
            if (c < 0) break;
        }
        cout << j << endl;
    }
}