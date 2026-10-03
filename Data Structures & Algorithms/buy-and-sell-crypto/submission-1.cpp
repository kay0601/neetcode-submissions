class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int left = 0;
        int max_profit = 0;
        for(int right=0; right<prices.size(); right++){
            if(prices[right] < prices[left]){
                left = right;
            }
            else {
                max_profit = max(prices[right] - prices[left], max_profit);
            }
        }
        return max_profit;
    }
};
