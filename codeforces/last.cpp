#include<bits/stdc++.h>
using namespace std;

long long int mysort(vector<int>arr)
{
    
    long long int s = arr.size();
    if (s==1) return 0;
    long long int p = s-1;
    long long int count = 0;
    long long int lastp;
    // for (long long int i:arr) cout << i << ' '; cout << endl;

    while (p > -1 )
    {
        while (arr[p] > arr[p-1] && p > 0) p--;
        if (p <= 0) break;
        if (p == lastp){
            
        }
        vector<int>less;
        vector<int>rest;
        
        for (long long int i = 0; i < s; i++){
            if (arr[i] < arr[p]) less.push_back(arr[i]);
            else if (arr[i]>arr[p]) rest.push_back(arr[i]);
        }
        less.push_back(arr[p]);
        count++;
        // arr.clear();
        arr.assign(less.begin(), less.end());
        arr.insert(arr.end(), rest.begin(), rest.end());
        for (long long int i:less) cout << i << ' '; cout << endl;
        for (long long int i:rest) cout << i << ' '; cout << endl;
        for (long long int i:arr) cout << i << ' '; cout << endl;
        cout << endl;
        // p=s-1;
        lastp = p;
        // p--;
    }
    return count;
}

int main()
{
    long long int n; cin >> n;
    for (long long int _=0; _<n; _++)
    {
        long long int num; cin >> num;
        vector<int>arr(num);
        for (long long int i = 0; i<num;i++) cin >> arr[i];
        cout << mysort(arr) << endl;
    }
}