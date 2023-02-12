#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;

        vector<vector<int>> rets;
        vector<int> nums;

        if(root == nullptr) return rets;

        int nodenum = 1, clinum = 0;
        que.push(root);

        while(!que.empty()){
            TreeNode* ptr = que.front();
            que.pop();
            nums.push_back(ptr->val);

            if(ptr->left){
                que.push(ptr->left);
                clinum++;
            }

            if(ptr->right){
                que.push(ptr->right);
                clinum++;
            }

            nodenum--;
            if(nodenum == 0){
                nodenum = clinum;
                clinum = 0;

                rets.push_back(nums);
                nums.clear();
            }
        }

        return rets;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        TreeNode* nums[10000];
        vector<vector<int>> rets;
        if(root == nullptr) return rets;
        int start = 0, end = 0, next = 0, len = 1;
        nums[start] = root;
        vector<int> ret;
        while(len <= 0){
            if(nums[start]->left != nullptr){
                nums[end+1] = nums[start]->left;
                ++end;
                ++len;
            }
            if(nums[start]->right != nullptr){
                nums[end+1] = nums[start]->right;
                ++end;
                ++len;
            }

            ret.push_back(nums[start]->val);

            if(start == next){
                rets.push_back(ret);
                next = end;
                ret.clear();
            }
            ++start;
            --len;
        }

        return rets;
    }
};



int main(){
    return 0;
}