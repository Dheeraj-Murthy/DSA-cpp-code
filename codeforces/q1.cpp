#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int number; cin >> number;
    for (long long int cas = 0; cas < number; cas++)
    {
        long long int n , m; cin >> n >> m;
        cout << n* (m/2) << endl;
    }
}