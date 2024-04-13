#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        vector<long long> A(sums.begin(), sums.end());
        sort(A.begin(), A.end());
        vector<int> tree(n + 2, 0);
        for (int i = 0; i < n + 1; ++i)
            insert(tree, i, 1);
        int count = 0;
        for (int i = 0; i < sums.size(); i++)
        {
            long long x = sums[i];
            int idx = lower_bound(A.begin(), A.end(), x) - A.begin();
            int lowerIdx = lower_bound(A.begin(), A.end(), x + lower) - A.begin();
            int upperIdx = upper_bound(A.begin(), A.end(), x + upper) - A.begin() - 1;
            insert(tree, idx, -1);
            count += preSum(tree, upperIdx) - preSum(tree, lowerIdx - 1);
        }
        return count;
    }

private:
    void insert(vector<int> &tree, int idx, int val)
    {
        ++idx;
        while (idx < tree.size())
        {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }
    int preSum(vector<int> &tree, int idx)
    {
        ++idx;
        int sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};