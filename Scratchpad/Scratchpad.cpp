#include <algorithm>
#include<vector>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> toReturn(n, 1);

    int product = 1;

    // products to the left.
    for (int i = 0; i < n; ++i)
    {
        toReturn[i] = product;
        product *= nums[i];
    }

    product = 1;

    // products to the right.
    for (int i = n - 1; i >= 0; --i)
    {
        toReturn[i] *= product;
        product *= nums[i];
    }

    return toReturn;
}

int maxArea(const std::vector<int>& height)
{
    // Variable init
    int highestLeft = 0;
    int highestRight = 0;
    int largestArea = 0;
    int horizontalDistance = height.size() -1;

    // Pointer init
    int leftPointer = 0;
    int rightPointer = height.size() -1;
    
    while (leftPointer < rightPointer)
    {
        int currentLeft = height[leftPointer];
        int currentRight = height[rightPointer];

        int currentLowestPillar = std::min(currentLeft, currentRight);
        int currentArea = currentLowestPillar * (leftPointer - rightPointer);

        largestArea = std::max(currentArea, largestArea);

        highestLeft = std::max(currentLeft, highestLeft);
        highestRight = std::max(currentRight, highestRight);

        if (currentLeft > currentRight)
         --rightPointer;
        else ++leftPointer;
    }


    return largestArea;
}

// Best time to buy and sell stock revision.
int maxProfit(std::vector<int>& prices) 
{
    int bestFound = 0;
    int currentLowest = prices[0];
    int currentHighest = 0;

    for(int i = 0; i < prices.size(); ++i)
    {
        currentHighest = std::max(currentHighest, prices[i]);

        if(prices[i] < currentLowest)
        {
            currentLowest = prices[i];
            currentHighest = currentLowest;
        }

        bestFound = std::max(bestFound, (currentHighest - currentLowest));
    }

    return bestFound;
}