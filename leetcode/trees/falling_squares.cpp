#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        set<int> indexes;
        for (auto &position : positions)
        {
            indexes.insert(position[0]);
            indexes.insert(position[0] + position[1]);
        }
        int n = indexes.size();
        vector<int> indices(indexes.begin(), indexes.end());
        vector<int> tree(4 * n);
        vector<int> result;

        for (auto &position : positions)
        {
            int left = lower_bound(indices.begin(), indices.end(), position[0]) - indices.begin();
            int right = lower_bound(indices.begin(), indices.end(), position[0] + position[1]) - indices.begin();

            int imax = query(tree, 0, 0, n - 1, left, right - 1);
            update(tree, 0, 0, n - 1, left, right - 1, imax + position[1]);
            // int maxHeight = query(tree, 0, 0, n-1, 0, n-1);
            // int maxHeight = tree[0];
            result.push_back(tree[0]);
        }
        return result;
    }

private:
    void update(vector<int> &tree, int idx, int ss, int se, int l, int r, int v)
    {
        if (r < ss || se < l)
            return;
        if (ss == se)
        {
            tree[idx] = max(tree[idx], v);
            // tree[idx] += v;
            return;
        }
        int mid = (ss + se) >> 1;
        update(tree, 2 * idx + 1, ss, mid, l, r, v);
        update(tree, 2 * idx + 2, mid + 1, se, l, r, v);
        tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    int query(vector<int> &tree, int idx, int ss, int se, int l, int r)
    {
        if (r < ss || se < l)
            return 0;
        if (l <= ss && se <= r)
        {
            return tree[idx];
        }
        int mid = (ss + se) >> 1;
        int left = query(tree, 2 * idx + 1, ss, mid, l, r);
        int right = query(tree, 2 * idx + 2, mid + 1, se, l, r);
        return max(left, right);
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    std::vector<std::vector<int>> positions1 = {{1, 2}, {2, 3}, {6, 1}};
    std::vector<int> result1 = solution.fallingSquares(positions1);
    std::cout << "Result for Test Case 1: ";
    for (int res : result1)
    {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    // Test Case 2
    std::vector<std::vector<int>> positions2 = {{100, 100}, {200, 100}};
    std::vector<int> result2 = solution.fallingSquares(positions2);
    std::cout << "Result for Test Case 2: ";
    for (int res : result2)
    {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    // Test Case 3
    std::vector<std::vector<int>> positions3 = {{9, 7}, {1, 9}, {3, 1}};
    std::vector<int> result3 = solution.fallingSquares(positions3);
    std::cout << "Result for Test Case 3: ";
    for (int res : result3)
    {
        std::cout << res << " ";
    }
    std::cout << std::endl;

    // You can add more test cases here

    return 0;
}
