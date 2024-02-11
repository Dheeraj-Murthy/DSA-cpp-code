#include<iostream>
#include<queue>
using namespace std;

// int bSearch(vector<int>arr, int k)
// {
//     int l=0; int r = arr.size()-1;
//     while (l <= r)
//     {
//         int m = (r - l)/2 + l;
//         if (k <= arr[m]) r = m-1;
//         else l = m+1;
//     }
//     return l;
// }

int main()
{
    long long int n, k; cin >> n >> k;
    priority_queue<long long int, vector<long long int>, greater<long long int>> queue;
    while (n > 0){
        long long int nxt; cin >> nxt;
        queue.push(nxt);
        if (queue.size() > k) queue.pop();
        n--;
    }
    cout << queue.top() << endl;
}