#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct TreeNode
{
    long long int index;
    long long int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(long long int idx, long long int val) : index(idx), value(val), left(nullptr), right(nullptr) {}
};

void calculateRootToNodeMedian(vector<long long> &result, TreeNode *root, const vector<long long> &parent, tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> &medians, vector<vector<long long>> &path_values)
{
    long long int nodeIndex = root->index;
    path_values[nodeIndex] = vector<long long>(path_values[parent[nodeIndex]].begin(), path_values[parent[nodeIndex]].end());
    medians.insert(root->value);

    long long int size = medians.size();
    result[nodeIndex] = *medians.find_by_order((size - 1) / 2);

    if (root->left != nullptr)
        calculateRootToNodeMedian(result, root->left, parent, medians, path_values);
    if (root->right != nullptr)
        calculateRootToNodeMedian(result, root->right, parent, medians, path_values);
    medians.erase(medians.upper_bound(root->value));
}

int main()
{
    long long int numNodes;
    cin >> numNodes;

    vector<long long> parent(numNodes), nodeValues(numNodes);
    for (long long int i = 0; i < numNodes; i++)
        cin >> parent[i];

    for (long long int i = 0; i < numNodes; i++)
        cin >> nodeValues[i];

    long long int rootIndex = -1;
    for (long long int i = 0; i < numNodes; i++)
    {
        if (parent[i] == -1)
        {
            rootIndex = i;
            break;
        }
    }

    vector<TreeNode> nodes;
    nodes.reserve(numNodes);
    for (long long int i = 0; i < numNodes; i++)
        nodes.emplace_back(i, nodeValues[i]);

    tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> medians;
    vector<vector<long long>> nodePaths(numNodes);

    for (long long int i = 0; i < numNodes; i++)
    {
        if (parent[i] == -1)
            continue;

        long long int parentNodeIndex = parent[i];

        if (nodes[parentNodeIndex].left == nullptr)
            nodes[parentNodeIndex].left = &nodes[i];
        else
            nodes[parentNodeIndex].right = &nodes[i];
    }

    TreeNode *root = &nodes[rootIndex];

    vector<long long> medianValues(numNodes);

    calculateRootToNodeMedian(medianValues, root, parent, medians, nodePaths);

    for (long long value : medianValues)
        cout << value << " ";

    return 0;
}