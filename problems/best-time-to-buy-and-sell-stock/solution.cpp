// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy_price = prices[0];
        for (int day = 1; day < prices.size(); ++day) {
            const int new_profit = prices[day] - buy_price;
            if (new_profit < 0)
                buy_price = prices[day];
            else if (new_profit > profit)
                profit = new_profit;
        }
        return profit;
    }
};
