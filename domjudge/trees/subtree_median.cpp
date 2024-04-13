#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    int size; // size of the subtree rooted at this node
    int median;

    TreeNode(int _value)
    {
        value = _value;
        left = nullptr;
        right = nullptr;
        size = 1;
        median = 0;
    }
};

// Function to compute the size and median of each subtree
void computeSizeAndMedian(TreeNode *root)
{
    if (!root)
        return;

    computeSizeAndMedian(root->left);
    computeSizeAndMedian(root->right);

    // Compute size of the subtree rooted at this node
    root->size = 1;
    if (root->left)
        root->size += root->left->size;
    if (root->right)
        root->size += root->right->size;

    // Compute the median
    if (!root->left && !root->right)
    {
        // Leaf node
        root->median = root->value;
    }
    else if (!root->left)
    {
        // No left child
        root->median = min(root->value, root->right->median);
    }
    else if (!root->right)
    {
        // No right child
        root->median = min(root->value, root->left->median);
    }
    else
    {
        // Node with both left and right children
        root->median = min(max(root->left->median, root->value), root->right->median);
    }
}

// Function to traverse the tree and print the median of each node
void printMedians(TreeNode *root)
{
    if (!root)
        return;

    printMedians(root->left);
    cout << root->median << " ";
    printMedians(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> parent(n), value(n);
    for (int i = 0; i < n; ++i)
        cin >> parent[i];

    for (int i = 0; i < n; ++i)
        cin >> value[i];

    // Construct the tree
    vector<TreeNode *> nodes(n, nullptr);
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new TreeNode(value[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (parent[i] != -1)
        {
            int p = parent[i];
            if (!nodes[p]->left)
                nodes[p]->left = nodes[i];
            else
                nodes[p]->right = nodes[i];
        }
    }

    // Compute size and median of each subtree
    computeSizeAndMedian(nodes[0]);

    // Print the median values
    printMedians(nodes[0]);
    cout << endl;

    // Clean up memory
    for (int i = 0; i < n; ++i)
        delete nodes[i];

    return 0;
}
