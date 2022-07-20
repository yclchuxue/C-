#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *le, TreeNode *ri) : value(val), left(le), right(ri) {}
};


class Solusion {
    public :
        // 根据前序遍历生成二叉树
        void make_from_pre(vector<int> nums){
            stack<TreeNode> newstack;

            if(nums.size() < 1) {
                TreeHead = nullptr;
                return;
            }

            
            for(auto iter = nums.begin(); iter != nums.end(); ++iter){
                if(*iter != -1){
                    TreeNode *P = new TreeNode;
                    P->value = *iter;
                }
            }

        }


        //前序遍历
        void preOrderTraverse1(){

        }

        //中序遍历
        void inOrderTraversel(){

        }

        //后序遍历
        void postOrderTraversel(){

        }
    private:
        TreeNode *TreeHead;
};

int main(){
    vector<int> nums = {};
}