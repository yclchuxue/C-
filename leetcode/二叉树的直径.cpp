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
 
class Solution {
public:
    vector<int> nums;

    int dp(TreeNode *node) {
        int le = 0, ri = 0;
        if(node->left) le = dp(node->left);

        if(node->right) ri = dp(node->right);

        nums.push_back(le+ri);

        if(le > ri) return le+1;
        else        return ri+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dp(root);

        sort(nums.begin(), nums.end());

        return nums[nums.size()-1];
    }
};