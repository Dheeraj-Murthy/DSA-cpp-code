#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int idx;
    int value;
    TreeNode *left;
    TreeNode *right;
    long long sum = 0;

    TreeNode(int _idx, int _value)
    {
        left = nullptr;
        right = nullptr;
        value = _value;
        idx = _idx;
    }
};

long long tree_Sum(TreeNode *root)
{
    if (!root)
        return 0;
    long long l = tree_Sum(root->left);
    long long r = tree_Sum(root->right);
    root->sum = l + r + root->value;
    return root->sum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> parent[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    // identify root
    int root_idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            root_idx = i;
            break;
        }
    }
    // generate tree
    vector<TreeNode *> nodes(n, nullptr);
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new TreeNode(i, value[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
            continue;

        int p = parent[i];

        if (nodes[p]->left == nullptr)
            nodes[p]->left = nodes[i];
        else
            nodes[p]->right = nodes[i];
    }

    // get the root
    TreeNode *root = nodes[root_idx];

    // continue;
    int _ = tree_Sum(root);
    for (int i = 0; i < n; i++)
        cout << nodes[i]->sum << ' ';

    return 0;
}