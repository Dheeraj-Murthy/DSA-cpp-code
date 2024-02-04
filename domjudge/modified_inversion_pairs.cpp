#include<bits/stdc++.h>
using namespace std;


long long int Merge(vector<long long int>&arr, long long int a, long long int b, long long int left, long long int mid, long long int right)
{
    long long int count = 0;
    long long int i = left;long long int j = mid+1;
    vector<int>temp;
    
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j]*a +b){ count+= right-j+1; i++;}
        else j++;
    }

    i = left; j = mid+1;
    while(i<=mid && j<=right)
    {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=right) temp.push_back(arr[j++]);
    for (long long int i = 0; i < temp.size(); i++) arr[left+i] = temp[i];
    return count;
}

long long int Mergesort(vector<long long int>&arr,long long int start, long long int end, long long int a, long long int b)
{
    if (end <= start) return 0;
    long long int count = 0;
    long long int mid = start + (end-start)/2;

    count += Mergesort(arr, start, mid, a, b);
    count += Mergesort(arr, mid+1, end, a, b);
    count += Merge(arr, a, b, start, mid, end);
    return count;
}

int main()
{
    long long int query; cin >> query;
    for (long long int linenum = 0; linenum<query; linenum++)
    {
        long long int n, a ,b; cin >> n >> a >> b;
        vector<long long int>arr(n);
        for (long long int i = 0; i < n; i++)
            cin >> arr[i];  
        long long int c = Mergesort(arr, 0, n-1, a, b);
        cout << c << endl;
    }
}