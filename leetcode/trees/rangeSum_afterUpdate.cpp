#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        long long n = nums1.size();
        vector<long long> tree(4 * n + 4, 0);
        buildTree(tree, nums1, 0, n - 1, 0);
        vector<long long> ans;
        long long sum = 0;
        for (auto it : nums2)
            sum += it;
        vector<long long> lazy(4 * n + 4, 0);
        for (auto q : queries)
        {
            if (q[0] == 1)
                rangeUpdate(tree, lazy, 0, 0, n - 1, q[1], q[2], 0);
            else if (q[0] == 2)
                sum += tree[0] * q[1];
            else
                ans.push_back(sum);
        }
        return ans;
    }

private:
    void buildTree(vector<long long> &tree, vector<int> &arr, long long ss, long long se, long long idx)
    {
        if (ss == se)
        {
            tree[idx] = arr[ss];
            return;
        }
        long long mid = (ss + se) >> 1;
        buildTree(tree, arr, ss, mid, 2 * idx + 1);
        buildTree(tree, arr, mid + 1, se, 2 * idx + 2);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
    // rest is the code for the lazy segment tree
    void rangeUpdate(vector<long long> &tree, vector<long long> &lazy, long long idx, long long ss, long long se, long long l, long long r, long long v)
    {
        if (lazy[idx] != 0)
        {
            tree[idx] = (se - ss + 1) - tree[idx];
            if (ss != se)
            {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }
            lazy[idx] = 0;
        }

        if (r < ss || se < l)
            return;

        if (l <= ss && se <= r)
        {
            tree[idx] = (se - ss + 1) - tree[idx];
            if (ss != se)
            {
                lazy[2 * idx + 1] = !lazy[2 * idx + 1];
                lazy[2 * idx + 2] = !lazy[2 * idx + 2];
            }
            return;
        }
        long long mid = (ss + se) >> 1;
        rangeUpdate(tree, lazy, 2 * idx + 1, ss, mid, l, r, v);
        rangeUpdate(tree, lazy, 2 * idx + 2, mid + 1, se, l, r, v);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
};