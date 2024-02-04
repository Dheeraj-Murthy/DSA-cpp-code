#include<bits/stdc++.h>
using namespace std;

long long int coins(long long int m, long long int w, long long int a, long long int b)
{
    a -= m%w;
    b -= m/w;
    long long int ans = 0;
    if (a > 0){
        long long int t = a/w;
        b += t;
        a -= t*w;
    }
    if (b < 0) ans -= b;
    if (a < 0) ans -= a;
    return ans;
}


int main()
{
    long long int test_cases; cin >> test_cases;
    for (long long int case_num = 0; case_num < test_cases; case_num++)
    {
        long long int m, worth, a, b;
        cin >> m >> worth >> a >> b;
        // if (b*worth +a >= m){
        //     cout << 0 << endl;
        //     continue;
        // }
        cout << coins(m, worth, a, b) << endl;    
    }
}