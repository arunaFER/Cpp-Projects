/*
Best Time to Buy and Sell Stock: Easy

You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

O(n) time
O(1) space
*/

#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices) {
    int l {0};
    int r {1};
    int maxProfit {0};

    while (r < prices.size()){
        if (prices.at(l) < prices.at(r)){
            int profit = prices.at(r) - prices.at(l);
            maxProfit = std::max(maxProfit, profit);
        } else {
            l = r;
        }
        ++r;
    }

    return maxProfit;
}

int main(){
    std::vector<int> prices {10,1,5,6,7,1};

    std::cout << "Output: " << maxProfit(prices) << std::endl;
    return 0;
}