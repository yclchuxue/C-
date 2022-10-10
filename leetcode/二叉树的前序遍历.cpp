#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void getvect(TreeNode* root, vector<int> &ret){
        if(root == nullptr){
            return ;
        }
        ret.push_back(root->val);
        getvect(root->left, ret);
        getvect(root->right, ret);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        
        if(root == nullptr){
            return ret;
        }
        ret.push_back(root->val);
        getvect(root->left, ret);
        getvect(root->right, ret);

        return ret;
    }
};

int main(){

}