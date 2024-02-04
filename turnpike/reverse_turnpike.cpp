#include<bits/stdc++.h>
using namespace std;

int main(){
    int c; cin >> c;
    int arr[c];
    for (int i = 0; i < c; i++) cin >> arr[i];
    sort(arr, arr+c);
    for (int i = 0; i < c; i++)
    {
        for (int j = i+1; j<c; j++)
        {
            cout << arr[j] - arr[i] << " ";
        }
    }
}