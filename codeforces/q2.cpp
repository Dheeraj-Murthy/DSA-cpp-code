#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int num; cin >> num;
    for (long long int cas = 0; cas < num; cas++)
    {
        long long int listnum; cin >> listnum;
        vector<long long int>one(listnum);
        vector<long long int>two(listnum);
        for (long long int i = 0; i < listnum; i++) cin >> one[i];
        for (long long int i = 0; i < listnum; i++) cin >> two[i];
        vector<pair<long long int,long long int> >arr;
        for (long long int i = 0; i < listnum; i++) arr.push_back({one[i], two[i]});
        sort(arr.begin(), arr.end());
        for (long long int i = 0; i < listnum; i++) cout << arr[i].first << ' '; cout << endl;
        for (long long int i = 0; i < listnum; i++) cout << arr[i].second << ' '; cout << endl;
    }
}