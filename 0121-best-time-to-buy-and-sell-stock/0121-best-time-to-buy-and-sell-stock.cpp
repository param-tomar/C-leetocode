class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minstock = prices[0];
        int maxprofit = 0;
        for(int i=0; i< prices.size(); i++){
            if(prices[i]<minstock){
                minstock = prices[i];
            }
            else if (prices[i] - minstock > maxprofit){
                 maxprofit = prices[i] - minstock;
            }
        }
        return maxprofit;
    }
}; 