class Solution {
public:
    int max_profit=0;
    int profit;
    int maxProfit(vector<int>& prices) {
        //buy the stock and sell the stock 
        //[10,1,5,6,7,1]
        //i,
        //j=i+1 ----n 
        //price[j]-price[i]=max and positive 
    //take extra conditon  if no positive value possible then return 0
        int n=prices.size()-1;
        for(int i=0;i<=n;i++) {
            int j=n;
            while(i<j){
                profit=prices[j]-prices[i];
                if(profit>0){
                    max_profit=max(max_profit,profit);
                    j--;

                }
                else{
                    j--;
                    
                }
                


            }

        }


    return max_profit;    
    }
};
