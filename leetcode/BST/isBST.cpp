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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return check(root, LLONG_MAX, LLONG_MIN);
    }

private:
    bool check(TreeNode *root, long long high, long long low)
    {
        if (!root)
            return true;
        // if (!root->right && !root->left) return true;
        int v = root->val;
        if (v >= high || v <= low)
            return false;
        bool lc = check(root->left, v, low);
        bool rc = check(root->right, high, v);
        return lc && rc;
    }
};