#include <vector>

int findMin(std::vector<int>& nums)
{    
    int leftSearchWindowBoundary = 0;
    int rightSearchWindowBoundary = nums.size() - 1;

    while (leftSearchWindowBoundary <= rightSearchWindowBoundary)
    {
        int midLocation =leftSearchWindowBoundary + (rightSearchWindowBoundary - leftSearchWindowBoundary) / 2;

        int leftValue = nums[leftSearchWindowBoundary];
        int rightValue = nums[rightSearchWindowBoundary];   
        int middleValue = nums[midLocation];

        if (leftValue <= rightValue)
            return leftValue;

        if (middleValue > rightValue)
            leftSearchWindowBoundary = midLocation + 1;       
        else
            rightSearchWindowBoundary = midLocation;    
    }

    return -1;
}