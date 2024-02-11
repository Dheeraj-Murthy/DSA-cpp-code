#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int>&arr, int l, int r);
//let's try a randomised quicksort algo
void quicksort(vector<int>&arr, int l, int r)
{
    if (l > r) return;
    int p = (rand()%(r-l+1)) + l;
    swap(arr[l], arr[p]);
    int k = Partition(arr, l, r);
    quicksort(arr, l, k-1);
    quicksort(arr, k+1, r);
}

int Partition(vector<int>&arr, int l, int r)
{
    int i = l+1; int j = r;
    while(i <= j)
    {
        while (i <= j && arr[i] <= arr[l]) i++;
        while (i <= j && arr[j] > arr[l])  j--;
        if ( i < j){ swap(arr[i], arr[j]);
        i++; j--;}
    }
    swap(arr[i-1], arr[l]);
    return i-1;
}


int main(){
    vector<int>v(3); v = {5,3,1};
    for (int i:v) cout << i << ' '; cout << endl;
    quicksort(v,0,2);
    for (int i:v) cout << i << ' '; cout << endl; 
}