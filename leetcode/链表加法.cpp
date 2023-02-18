#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    int getnum(ListNode* head){
        int num = 0;
        
        while(head != nullptr){
            cout << " num " << endl;
            num = num*10 + head->val;
            head = head->next;
        }
        
        return num;
    }
    
    ListNode* creatlist(int num){
        ListNode* ret;
        
        while(num!=0){
            int value = num%10;
            
            ListNode* ptr = new ListNode(value);
            if(ret == nullptr){
                ret = ptr;
            }else{
                ptr->next = ret;
                ret = ptr;
            }
            num = num/10;
            cout << value << "\t" << num << endl;
        }

        ListNode* ret1 = ret;

        if(ret != nullptr) {
            cout << ret->val << endl;
            ListNode* ppp = ret->next;
            cout << "ret is not nullptr" << endl;

        }

        while(ret1){
            cout << ret1->val << "\t";
            ret1 = ret1->next;
        }
        
        return ret;
    }
    
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        int num1, num2;
        
        num1 = getnum(head1);
        num2 = getnum(head2);
        auto ret = creatlist(num1+num2);

        cout << " over " << endl;

        return ret;
    
    }
};

// class Solution {
// public:
//     ListNode* addInList(ListNode* head1, ListNode* head2) {
//         // write code here

//     }
// };

int main(){
    // Solution1 P;

    // ListNode* head1 = P.creatlist(966);
    // ListNode* head2 = P.creatlist(34);

    // ListNode* ret = head1;
    // // while(ret){
    // //     cout << ret->val << "\t";
    // //     ret = ret->next;
    // // }
    // // ret = head2;
    // // while(ret){
    // //     cout << ret->val << "\t";
    // //     ret = ret->next;
    // // }

    // ret = P.addInList(head1, head2);

    // while(ret){
    //     cout << ret->val << "\t";
    //     ret = ret->next;
    // }

    string str = "900";

    cout << str.size() << endl;

    return 0;
}