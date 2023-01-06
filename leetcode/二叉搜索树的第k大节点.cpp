#include <cstddef>
#include <iostream>
#include <vector>
// #include 

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if(k == 1 && root->right == nullptr)    return root->val;

        int num = 0;
        bool ret;
        if(root != nullptr){
            ret = dg(root, k, num);
        }
        return num;
    }

    bool dg(TreeNode* root , int k, int& num){
        bool ret = false;
        if(root->right == nullptr) {
            ++num;
        }else{
            ret = dg(root->right, k, num);
            if(!ret){
                ++num;
            }else{
                return ret;
            }
        }
        
        if(num == k){
            num = root->val;
            return true;
        }else if(root->left != nullptr){
            ret = dg(root->left, k, num);
        }

        return ret;
    }
};