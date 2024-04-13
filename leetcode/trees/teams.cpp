#include <bits/stdc++.h>
using namespace std;

// these are the codes for building the binary index tree
void UpdateTree(vector<int> &tree, int n, int i, int x)
{
    // i++;
    while (i < n + 1)
    {
        tree[i] += x;
        i += i & (-i);
    }
}

vector<int> Build(vector<int> &arr, int n)
{
    vector<int> tree(n + 1, 0);
    for (int i = 0; i < n; i++)
        UpdateTree(tree, n, i + 1, arr[i]);
    return tree;
}

int presum(vector<int> &tree, int i)
{
    int s = 0;
    // i++;
    while (i > 0)
    {
        s += tree[i];
        i -= i & (-i);
    }
    return s;
}

int numTeams(vector<int> &rating)
{
    int n = rating.size();
    vector<int> sorted(rating);
    sort(sorted.begin(), sorted.end());
    vector<int> ansl(n, 0);
    vector<int> ansr(n, 0);
    vector<int> tree(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int t = lower_bound(sorted.begin(), sorted.end(), rating[i]) -
                sorted.begin() + 1;
        ansl[i] = presum(tree, n) - presum(tree, t - 1);
        UpdateTree(tree, n, t, 1);
    }
    tree.clear();
    tree.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        int t = lower_bound(sorted.begin(), sorted.end(), rating[i]) -
                sorted.begin() + 1;
        ansr[i] = presum(tree, t - 1);
        UpdateTree(tree, n, t, 1);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(ansl[i], ansr[i]);
        cout << ansl[i] << ' ' << ansr[i] << endl;
    }

    return sum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << numTeams(arr) << endl;
    vector<int> Rarr(arr.rbegin(), arr.rend());
    cout << numTeams(Rarr) << endl;
    return 0;
}