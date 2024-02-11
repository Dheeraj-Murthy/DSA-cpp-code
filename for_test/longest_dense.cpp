#include<bits/stdc++.h>
using namespace std;

int Longest_Dense_Substring(string s)
{
    int n = s.size();
    vector<int>T(n, -1);
    int c = n; int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1') c++; else c--;
        if (c > n) maxi = i+1;
        else 
        {
            if (T[c-1] != -1 && i - T[c-1] > maxi) maxi = i - T[c-1];
            if (T[c] == -1) T[c] = i;
        }
    }
    return maxi;
}

int main()
{
    string s; cin >> s;
    int ans = Longest_Dense_Substring(s);
    cout << ans;
}