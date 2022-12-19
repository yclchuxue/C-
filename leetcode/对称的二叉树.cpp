#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool dg(TreeNode *left_ptr, TreeNode *righ_ptr){
        if(!left_ptr && !righ_ptr){
            return true;
        }
        if(left_ptr && righ_ptr){
            if(left_ptr->val == righ_ptr->val){
                return dg(left_ptr->left, righ_ptr->right) && dg(left_ptr->right, righ_ptr->left);
            }else{
                return false;
            }
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;

        return dg(root->left, root->right);
    }
};