#include <iostream>
#include <vector>

// you are given an array prices where prices[i] is the price of a given stock on the ith day
// You want to maximize your profit by choosing a single day to buy one stock and choosing a
// different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit,
// return 0;

// / If the prices are in decreasing order, no profit can be made.
// If the prices are increasing order, profit can be made at the nth day.
// if the prices are neither increasing or decreasing, profit can also be possibly made here. We can buy a min value and find the highest profit
// grab the lowest price at the CURRENT day.
// if the current price is less than the tracked lowest price, we can ignore those

// My Solution: 0ms Runtime.
int maxProfit(std::vector<int>& prices) {
    int currentLowest;
    int profit;

    profit = 0;
    currentLowest = prices.at(0);

    for (int i = 1; i < prices.size(); i++) {
        if ((prices.at(i) > currentLowest) && ((prices.at(i) - currentLowest) > profit)) {
            profit = prices.at(i) - currentLowest;
        }
        if (prices.at(i) < currentLowest) {
            currentLowest = prices.at(i);
        }
    }


    return profit;
}

int main() {

    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << maxProfit(prices1) << std::endl;

    std::vector<int> prices = {7, 6, 4, 3, 1};
    std::cout << "profit: " << maxProfit(prices) << std::endl;

    // std::vector<int> prices3 = {1, 2};
    // std::cout << maxProfit(prices3) << std::endl;

    return 0;
}