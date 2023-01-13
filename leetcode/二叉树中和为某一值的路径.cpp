#include <cstddef>
#include <iostream>
#include <vector>
#include <deque>

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
private:
    int tar;

public:
    void dfs(TreeNode *root, int count, vector<int>& nums, vector<vector<int>>& rets){
        count += root->val;
        nums.push_back(root->val);
        if(count == tar){
            cout << root->val << endl;
            if(!root->left && !root->right){
                rets.push_back(nums);
            }

        }
        cout << root->val << endl;

        if(root->left != nullptr){
            dfs(root->left, count, nums, rets);
        }
        if(root->right != nullptr){
            dfs(root->right, count, nums, rets);
        }
        nums.pop_back();
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        // deque<TreeNode *> Q;
        tar = target;
        vector<vector<int>> rets;
        if(root == nullptr) return rets;
        else{
            if(root->val == target && !root->left && !root->right){
                vector<int> nums;
                nums.push_back(root->val);
                rets.push_back(nums);
            }
        }

        
        if(root->left != nullptr){
            vector<int> nums;
            nums.push_back(root->val);
            dfs(root->left, root->val, nums, rets);
        }
        if(root->right != nullptr){
            vector<int> nums;
            nums.push_back(root->val);
            dfs(root->right, root->val, nums, rets);
        }

        return rets;
    }
};