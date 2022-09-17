#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode *ans;
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root == nullptr){
            return false;
        }
        bool lan = dfs(root->left, p, q);
        bool ran = dfs(root->right, p, q);

        //   p,q为下方的子节点                   p||q是root自己
        if((lan && ran) || ((root->val == p->val || root->val == q->val)&&(lan || ran))){
            ans = root;
        }

        return lan || ran || (root->val == p->val) || (root->val == q->val);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
        dfs(root, p, q);
        return ans;
    }
};

int main(){

}