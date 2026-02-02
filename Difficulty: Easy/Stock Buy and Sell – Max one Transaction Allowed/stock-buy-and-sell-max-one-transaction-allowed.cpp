class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0; // safety check

        int minPrice = prices[0];    // first price
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
