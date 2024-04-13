#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        InOrder(root, count, k);
        return ans;
    }

private:
    void InOrder(TreeNode *root, int &count, int k)
    {
        if (!root)
            return;
        if (count > k)
            return;
        InOrder(root->left, count, k);
        count++;
        if (count == k)
        {
            ans = root->val;
            return;
        }
        InOrder(root->right, count, k);
    }
};