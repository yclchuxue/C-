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
    queue<TreeNode *> qu;
    vector<vector<int>> counts;

    void dg(vector<int> &rets){
        TreeNode *node = qu.front();
        if(node == nullptr) return;
        rets.push_back(node->val);
        qu.pop();
        if(node->left){
            qu.push(node->left);
        }
        if(node->right){
            qu.push(node->right);
        }

        if(!qu.front()){
            qu.pop();
            qu.push(nullptr);
            counts.push_back(rets);
            vector<int> nums;
            if(!qu.empty()){
                dg(nums);
            }else{
                return;
            }
        }else{
            if(!qu.empty()){
                dg(rets);
            }else{
                return;
            }
        }
    } 

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> rets;
        if(root != nullptr){
            qu.push(root);
            qu.push(nullptr);
            dg(rets);
        }

        return counts;
    }
};