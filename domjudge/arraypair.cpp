#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n; cin >> n;
    unordered_map<ll, ll>dif;
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ll temp; cin >> temp;
        temp -= i;
        ans+=dif[temp];
        dif[temp]++;
    }
    cout << ans;
}