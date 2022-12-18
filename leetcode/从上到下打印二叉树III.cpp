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

    void dg(vector<int> &rets, bool leftright){
        TreeNode *node = qu.front();
        if(node == nullptr){
            return;
        }
        if(leftright){
            rets.push_back(node->val);
        }else{
            rets.insert(rets.begin(), node->val);
        }
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
                dg(nums, !leftright);
            }else{
                return;
            }
        }else{
            if(!qu.empty()){
                dg(rets, leftright);
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
            dg(rets, true);
        }

        return counts;
    }
};