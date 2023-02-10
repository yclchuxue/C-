#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, len = prices.size();
        if(len < 2){
            return ret;
        }
        int min_price = prices[0];
        for(int i = 1; i < len; i++){
            if(prices[i] > min_price){
                ret = max(prices[i]-min_price, ret);
            }else{
                min_price = min(prices[i], min_price);
            }
        }

        return ret;
    }
};

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, len = prices.size();
        if(len < 2 )    return ret;

        int min_pri = prices[0];

        for(int i = 1; i < len; ++i){
            if(prices[i] > min_pri){
                ret = max(prices[i]-min_pri, ret);
            }else{
                ret = min(prices[i], min_pri);
            }
        }

        return ret;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, len = prices.size();
        if(len < 2){
            return ret;
        }
        
        int min_price = prices[0], ret0;
        for(int i = 1; i < len; i++){
            if(prices[i] > min_price){
                int x = prices[i]-min_price;
                if(x > ret){
                    ret0 = ret;
                    ret = x;
                }
            }else{
                min_price = min(prices[i], min_price);
            }
        }

        return ret+ret0;
    }
};