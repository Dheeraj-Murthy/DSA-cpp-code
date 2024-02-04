#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int testcases;
    cin >> testcases;
    vector<long long int> result;
    for(long long int i=0;i<testcases;i++){
        long long int m, k, a1, ak, fancy_coins=0;
        cin >> m >> k >> a1 >> ak;
        ak = ak-(m/k);
        a1 = a1-m%k;
        if (a1>0){
            long long int temp = a1/k;
            ak = ak + (temp);
            a1 = a1 - (k*temp);
        }
        if (ak < 0){
            fancy_coins -= ak;
        }
        if (a1 < 0){
            fancy_coins -= a1;
        }
        result.push_back(fancy_coins);
    }
    for (int it: result) cout << it << endl;
}