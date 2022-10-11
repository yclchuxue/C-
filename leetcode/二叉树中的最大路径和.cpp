#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

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
    
    int recursion(TreeNode* root, vector<int>& nums) {
        if(root == nullptr){
            return 0;
        }
        int left = recursion(root->left, nums);
        int right = recursion(root->right, nums);
        int num = root->val;
        if(left > 0){
            num += left;
        }
        if(right > 0){
            num += right;
        }

        nums.push_back(num);
        nums.push_back(root->val);
        
        if(left > right){
            if(left + root->val > 0){
                return left + root->val;
            }else{
                return 0;
            }
        }else{
            if(right + root->val > 0){
                return right + root->val;
            }else{
                return 0;
            }
        }
    }

    int maxPathSum(TreeNode* root) {
        vector<int> nums;

        recursion(root, nums);
        sort(nums.begin(), nums.end());
        return nums[nums.size()-1];
    }

};

