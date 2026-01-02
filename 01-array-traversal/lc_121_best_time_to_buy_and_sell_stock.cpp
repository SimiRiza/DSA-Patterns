class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_yet = prices[0];
        int profit =0;
        int curr = 1;
        while(curr<prices.size()){
            if(prices[curr]<min_yet){
                min_yet=prices[curr];
            }
             else{
               if(prices[curr]-min_yet>profit){
                profit = prices[curr]-min_yet;
               }
            }
            curr++;
        }
        return profit;
    }
};