/*
=================================================
Problem: Best Time to Buy and Sell Stock (LC #121)
=================================================

Problem Statement:
You are given an array prices where prices[i] is the price of a given stock on
the ith day. You want to maximize your profit by choosing a single day to buy
one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve. If you cannot achieve any profit,
return 0.

Approach Used:
Single Pass with Tracking Minimum Price
- Maintain the minimum price encountered so far as the best buying price.
- At each day, calculate the profit if sold on that day.
- Update the maximum profit accordingly.
- Update the best buying price whenever a lower price is found.

Complexity Analysis:
Time Complexity: O(n)
Space Complexity: O(1)

Why This Approach?
By tracking the minimum buying price and calculating profit in a single pass,
we avoid unnecessary comparisons and achieve optimal linear time complexity.

Concepts Used:
Arrays, Greedy Strategy

Problem Link:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
=================================================
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,bestbuy=prices[0];
        for(int i=1;i<prices.size();i++) {
            if(prices[i] > bestbuy) {
                maxprofit=max(maxprofit,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
        return maxprofit;
    }
};
