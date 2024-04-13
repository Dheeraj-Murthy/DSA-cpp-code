#include <bits/stdc++.h>
using namespace std;

int prefixSum(vector<int> tree, int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += tree[i];
        i -= i & (-i);
    }
    return sum;
}

void updateBIT(vector<int> &tree, int n, int i, int x)
{
    while (i < n + 1)
    {
        tree[i] += x;
        i += i & (-i);
    }
}

vector<int> BuildBIT(vector<int> arr, int n)
{
    vector<int> tree(n + 1, 0);
    for (int i = 0; i < n; i++)
        updateBIT(tree, n, i + 1, arr[i]);
    return tree;
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> tree = BuildBIT(arr, 8);
    for (int i = 0; i < 9; i++)
        cout << tree[i] << ' ';
    return 0;
}