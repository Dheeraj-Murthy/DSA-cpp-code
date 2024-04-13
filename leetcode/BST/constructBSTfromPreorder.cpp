#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

//  * Definition for a binary tree node.
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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        stack<TreeNode *> stk;
        TreeNode *root = new TreeNode(preorder[0]);
        stk.push(root);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *cur = new TreeNode(preorder[i]);
            if (cur->val < stk.top()->val)
            {
                stk.top()->left = cur;
                stk.push(cur);
            }
            else
            {
                TreeNode *last = stk.top();
                while (!stk.empty() && cur->val > stk.top()->val)
                {
                    last = stk.top();
                    stk.pop();
                }
                last->right = cur;
                stk.push(cur);
            }
        }
        return root;
    }
};