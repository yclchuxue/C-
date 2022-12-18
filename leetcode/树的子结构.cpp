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
    bool dg(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A || A->val != B->val) return false;
        return dg(A->left, B->left) && dg(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B || !A) return false;

        if(A->val == B->val) {
            if(dg(A, B)) return true;
        }
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};