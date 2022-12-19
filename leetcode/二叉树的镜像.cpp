#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root) return root;

        TreeNode *ptr = root->left;
        root->left = root->right;
        root->right = ptr;

        if(root->left) mirrorTree(root->left);
        if(root->right) mirrorTree(root->right);

        return root;
    }
};