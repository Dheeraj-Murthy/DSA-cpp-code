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

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    vector<int> ans(n, 0);
    vector<int> tree(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int t = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
        ans[i] = presum(tree, t - 1);
        UpdateTree(tree, n, t, 1);
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 2, 6, 1};
    vector<int> ans = countSmaller(arr);
    for (int it : ans)
        cout << it << ' ';
}
