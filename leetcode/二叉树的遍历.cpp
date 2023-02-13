#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void fprint(TreeNode * root, vector<int>& nums){
        if(root==nullptr) return;
        else{
            nums.push_back(root->val);
            if(root->left) fprint(root->left, nums);
            if(root->right) fprint(root->right, nums);
        }
    }
    
    void cprint(TreeNode * root, vector<int>& nums){
        if(root==nullptr) return;
        else{
            if(root->left) cprint(root->left, nums);
            nums.push_back(root->val);
            if(root->right) cprint(root->right, nums);
        }
    }
    
    void eprint(TreeNode * root, vector<int>& nums){
        if(root==nullptr) return;
        else{
            if(root->left) eprint(root->left, nums);
            if(root->right) eprint(root->right, nums);
            nums.push_back(root->val);
        }
    }
    
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        
        vector<vector<int>> rets;
        vector<int> frets, crets, erets;
        
        fprint(root, frets);
        cprint(root, crets);
        eprint(root, erets);
        
        rets.push_back(frets);
        rets.push_back(crets);
        rets.push_back(erets);
        
        return rets;
    }
};