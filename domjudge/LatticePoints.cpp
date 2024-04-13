#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define ndl '\n'
#define int long long

void solve(ll tc) {
    long double r, k; cin >> r >> k;
    int x = 1,y = floor(r), ans = 0, z = floor(k)+1;
    while(x <= floor(r) && y >= 0){
        if((x*x) + (y*y) < (r*r)){
            int lft = max(z, -y);
            ans += max(0LL, y-lft+1);
            x++;
        } else {
            y--;
        }
    }
    ans *= 2;
    y = floor(r);
    if(y == r) {
        y--;
    }
    int lft = max(z, -y);
    ans += max(y-lft+1, 0LL);
    cout << ans << ndl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T=1;
    // cin>>T;
    for (ll tc = 1; tc <=T; tc++) solve(tc);
    return 0;
}