#include <cstddef>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    queue<TreeNode*> qu;

    void dg(vector<int>& rets, TreeNode * node){
        rets.push_back(node->val);
        qu.pop();
        if(node->left) qu.push(node->left); 
        if(node->right) qu.push(node->right);

        if(!qu.empty())     dg(rets, qu.front());
        else                return;
    }
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> rets;
        if(root != nullptr){
            qu.push(root);
            dg(rets, qu.front());
        }
        return rets;
    }
};