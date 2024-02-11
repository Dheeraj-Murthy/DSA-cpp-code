#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    int ans=1;
    for (int i = 0; i < n; i++) ans*=(i+1);
    return ans;
}

string posfactor(int n, int k)
{
    int f = factorial(n);
    vector<int> arr(n);
    string ans;
    for (int i = 0; i < n; i++) arr[i] = i+1;
    for (int i = 0; i < n; ++i) {
        f /= (n - i);
        int index = (k - 1) / f;
        ans += to_string(arr[index]);
        arr.erase(arr.begin() + index);
        k -= index * f;
    }

    return ans;
}


int main()
{
    int num; cin >> num;
    for (int testcases = 0; testcases<num; testcases++)
    {
        int n, k; cin >> n >> k;
        string ans = posfactor(n,k);
        cout << posfactor(n,k) << endl; cout << endl;
    }
    return 0;
}