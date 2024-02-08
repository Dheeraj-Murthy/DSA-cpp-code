#include<bits/stdc++.h>
using namespace std;

void bubblesort(vector<int>&arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {   
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void selectionsort(vector<int>&arr)
{
    int n = arr.size();
    for(int i = n-1; i >= 0; i--)
    {
        int m = 0;
        for (int j = 1; j < i; j++) if (arr[m] < arr[j]) m = j;
        if (m != i) swap(arr[m], arr[i]);
        cout << arr[m] << i;
    }
}

void insertionsort(vector<int>&arr)
{
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        int t = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > t){ arr[j+1] = arr[j]; j--; }
        arr[j+1] = t;
    }
}

int main()
{
    vector<int>arr; arr = {8,7,6,5,4,3,2,1}; 
    bubblesort(arr);
    for(int i: arr) cout << i << ' ';
    arr = {8,7,6,5,4,3,2,1}; cout << endl;
    selectionsort(arr);
    for(int i: arr) cout << i << ' '; cout << endl;
    arr = {8,7,6,5,4,3,2,1};
    insertionsort(arr);
    for(int i: arr) cout << i << ' '; cout << endl;
}