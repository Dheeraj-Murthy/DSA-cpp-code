#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int idx;
    int value;
    TreeNode* left;
    TreeNode* right;
    long long m = INT_MAX;
    
    TreeNode(int _idx, int _value)
    {
        left = nullptr;
        right = nullptr;
        value = _value;
        idx = _idx;
    }
};

bool comp(int a, int b){
    return a < b;
}

void tree_Sum(TreeNode* root, long long m){
    if (!root) return;
    root->m = m > root->value ? root->value : m;
    tree_Sum(root->left, root->m);
    tree_Sum(root->right, root->m);
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> parent(n), value(n);
    for(int i=0; i<n; i++)
        cin >> parent[i];
        
    for(int i=0; i<n; i++)
        cin >> value[i];
        
    // identify root
    int root_idx = -1;
    for(int i=0; i<n ;i++)
    {
        if(parent[i] == -1)
        {
            root_idx = i;
            break;
        }   
    }
    // generate tree
    vector<TreeNode*> nodes(n, nullptr);
    for(int i=0; i<n; i++)
    {
        nodes[i] = new TreeNode(i, value[i]);
    }
    
    for(int i=0; i<n; i++)
    {
        if(parent[i] == -1)
            continue;
        
        int p = parent[i];
        
        if(nodes[p] -> left == nullptr)
            nodes[p] -> left = nodes[i];
        else 
            nodes[p] -> right = nodes[i];
    }
    
    // get the root
    TreeNode *root = nodes[root_idx];
    
    // continue;
    tree_Sum(root, INT_MAX);
    for (int i = 0; i < n; i++) cout << nodes[i]->m << ' ';
    
    
    

    return 0;
}