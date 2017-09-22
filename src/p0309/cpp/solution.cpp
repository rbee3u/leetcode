/******************************************************************************
                prev_buy        prev_buy_cool   prev_sell       prev_sell_cool
curr_buy        ×               ×               ×               √
curr_buy_cool   √               √               ×               ×
curr_sell       √               √               ×               ×
curr_sell_cool  ×               ×               √               √
******************************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyState=0, bcState=0, sellState=0, scState=1;
        int buyProfit,  bcProfit,  sellProfit,  scProfit=0;
        int buyState2,  bcState2,  sellState2,  scState2;
        int buyProfit2, bcProfit2, sellProfit2, scProfit2;
        for (auto nowPrice : prices) {

            buyState2 = 0; scState && (buyState2=1, buyProfit2=scProfit-nowPrice);

            bcState2 = 0; buyState && (bcState2=1, bcProfit2=buyProfit);
            bcState && (bcState2=1, bcProfit2=max(bcProfit2, bcProfit));

            sellState2 = 0; buyState && (sellState2=1, sellProfit2=buyProfit+nowPrice);
            bcState && (sellState2=1, sellProfit2=max(sellProfit2, bcProfit+nowPrice));

            scState2 = 0; sellState && (scState2=1, scProfit2=sellProfit);
            scState && (scState2=1, scProfit2=max(scProfit2, scProfit));

            buyState = buyState2; buyProfit = buyProfit2;
            bcState = bcState2; bcProfit = bcProfit2;
            sellState = sellState2; sellProfit = sellProfit2;
            scState = scState2; scProfit = scProfit2;
        }
        int ret = 0;
        if (sellState && (sellProfit > ret)) {
            ret = sellProfit;
        }
        if (scState && (scProfit > ret)) {
            ret = scProfit;
        }
        return ret;
    }
};

