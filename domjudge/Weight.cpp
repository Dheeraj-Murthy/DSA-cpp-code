#include<unordered_map>
#include<iostream>
using namespace std;

int main()
{
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        unordered_map<long long int, int>mpp;
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long int t; cin >> t;
            mpp[t]++;
        }
        for (auto it:mpp){
            int v = it.second;
            cout << v<<' ';
            ans += ( v*(v-1)/2);
        }
        cout << ans << endl;
    }
}