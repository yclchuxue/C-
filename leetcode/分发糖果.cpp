#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //超时
    int candy1(vector<int>& ratings) {
        int len = ratings.size();

        if(len < 1){
            return 0;
        }if(len == 1){
            return 1;
        }   
        vector<int> nums = ratings;
        int before = 1, score = ratings[0], ret = 1;
        nums[0] = 1;

        for(int i = 1, j = 0; i < ratings.size(); i++, j++){
            if(ratings[i] > score){
                before++;
                nums[i] = before;
                ret += before;
            }else if(score > ratings[i] && before == 1){
                ret += 2;
                before = 1;
                nums[i] = before;
                nums[i-1]++;
                int x = j-1, y = i-1;
                cout << "???" << endl;
                while(1){
                    if(x >= 0){
                        cout << x << "\t" << y << endl;
                        if(ratings[x] > ratings[y] && nums[x] <= nums[y]){
                            nums[x]++;
                            ret++;
                            x--;
                            y--;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }else{
                ret += 1;
                before = 1;
                nums[i] = before;
            }
            score = ratings[i];
        }
        return ret;
    }

    int candy(vector<int> &ratings){
        int len = ratings.size();
        if(len < 1){
            return 0;
        }if(len == 1){
            return 1;
        } 

        vector<int> nums = ratings;
        nums[0] = 1;

        for(int i = 1; i < len; i++){
            if(ratings[i] > ratings[i-1]){
                nums[i] = nums[i-1]+1;
            }else{
                nums[i] = 1;
            }
        }
        int ret = nums[len-1];
        for(int i = len - 2; i >= 0; i--){
            if(ratings[i] > ratings[i+1] && nums[i] <= nums[i+1]){
                nums[i] = nums[i+1]+1;
            }
            ret += nums[i];
        }

        return ret;
    }
};

int main(){
    vector<int> nums = {1, 2, 87, 87, 87, 2, 1};

    Solution P;

    cout << P.candy(nums) << endl;
}