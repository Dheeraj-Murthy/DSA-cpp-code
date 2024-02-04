#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n; cin >> n;
    long long int a = 0;
    long long int t = 0;
    for (int i = 0; i <n;i++)
    {
        long long int ta, tt;
        cin >> tt >> ta;   
        a+=ta;
        t+=tt;     
    }
    if (t > a) cout << "Takahashi";
    else if (a > t) cout << "Aoki";
    else cout << "Draw";
}