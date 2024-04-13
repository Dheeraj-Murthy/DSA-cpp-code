#include <bits/stdc++.h>
using namespace std;

// this is the functions to build and maintaing a sum tree
int findNextExp(int i)
{
    int e = 1;
    while (e < i)
        e *= 2;

    return e;
}

vector<int> BuildTree(int n, vector<int> arr)
{
    int na = findNextExp(n);
    for (int i = n; i < na; i++)
        arr.push_back(0);
    n = na;
    vector<int> tree(2 * n - 1);
    for (int i = 0; i < n; i++)
        tree[n - 1 + i] = arr[i];
    int i = n - 2;
    while (i > -1)
    {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        i--;
    }
    return tree;
}

void Update(vector<int> &tree, int i, int x)
{
    tree[i] = x;
    i = (i - 1) / 2;
    while (i > -1)
    {
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
        i = (i - 1) / 2;
    }
}

int RangeSum(vector<int> &tree, int l, int r, int s, int e, int i)
{
    if (l < s && e < r)
        return tree[i];
    if (r < s || e < l)
        return 0;
    int m = s + (e - s) / 2;
    int lsum = RangeSum(tree, l, r, s, m, 2 * i + 1);
    int rsum = RangeSum(tree, l, r, m + 1, e, 2 * i + 2);
    return lsum + rsum;
}

void printtree(vector<int> tree, int n)
{
    int c = 0;
    for (int i = 1; i <= n; i *= 2, c++)
    {

        for (int j = 0; j < n - c; j++)
            cout << "...";
        for (int j = 0; j < i; j++)
            cout << setw(3) << (tree[i + j - 1]) << "  ";
        cout << endl;
    }
}

int main()
{
    vector<int> arr{5, 2, 6, 1};
    // vector<int>tree = BuildTree(4, arr);
    // printtree(tree, 4);
    vector<int> B(arr);
    sort(B.begin(), B.end());
}

// below are the functions for the

vector<int> BuildTree(int n, vector<int> arr)
{
    int na = findNextExp(n);
    for (int i = n; i < na; i++)
        arr.push_back(0);
    n = na;
    vector<int> tree(2 * n - 1);
    for (int i = 0; i < n; i++)
        tree[n - 1 + i] = arr[i];
    int i = n - 2;
    while (i > -1)
    {
        int l = tree[2 * i + 1];
        int r = tree[2 * i + 2];
        tree[i] = l < r ? l : r;
        i--;
    }
    return tree;
}

void Update(vector<int> &tree, int i, int x)
{
    tree[i] = x;
    i = (i - 1) / 2;
    while (i > -1)
    {
        int l = tree[2 * i + 1];
        int r = tree[2 * i + 2];
        tree[i] = l < r ? l : r;
        i = (i - 1) / 2;
    }
}

int RangeMin(vector<int> &tree, int l, int r, int s, int e, int i)
{
    if (l < s && e < r)
        return tree[i];
    if (r < s || e < l)
        return INT_MAX;
    int m = s + (e - s) / 2;
    int lmin = RangeMin(tree, l, r, s, m, 2 * i + 1);
    int rmin = RangeMin(tree, l, r, m + 1, e, 2 * i + 2);
    return lmin < rmin ? lmin : rmin;
}
