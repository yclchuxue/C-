#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 2 1 3
class Solution {
public:
    bool istrue(TreeNode *node, int fx, int& max, int& min){
        bool le = false, ri = false;
        int le_max, le_min, ri_max, ri_min;
        min = node->val;
        max = node->val;
        if(node->left){
            if(node->left->val < node->val){
                le = istrue(node->left, -1, le_max, le_min);
                if(le && node->val <= le_max){
                    return false;
                }
                if(min > le_min) min = le_min;
                if(max < le_max) max = le_max;
            }
        }else{
            le = true;
        }
        if(node->right){
            if(node->right->val > node->val){
                ri = istrue(node->right, 1, ri_max, ri_min);
                if(ri && node->val >= ri_min){
                    return false;
                }
                if(min > ri_min) min = ri_min;
                if(max < ri_max) max = ri_max;
            }
        } else{
            ri = true;
        }

        // cout << le << "\t" << le_num << "\t" << ri << "\t" << ri_num << "\t" << node->val << endl;
        
        
        if(le && ri)    return true;
        else            return false;
    }

    bool isValidBST(TreeNode* root) {
        int max, min;
        return istrue(root, 0, max, min);
    }
};