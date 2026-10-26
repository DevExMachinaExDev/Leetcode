#include <vector>

// Simple O(N) solution uses a single loop and checks if value is higher than the highest found, if it does calculate profit if its less take that as the new lowest and reset the highest to prevent out of order errors.
int maxProfit(std::vector<int>& prices) 
{
    int lowest = prices[0];
    int highest = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > highest)
            highest = prices[i];

        maxProfit = std::max(maxProfit, highest - lowest);

        if (prices[i] < lowest)
        {
            lowest = prices[i];
            highest = prices[i];
        }
    }

    return maxProfit;
}