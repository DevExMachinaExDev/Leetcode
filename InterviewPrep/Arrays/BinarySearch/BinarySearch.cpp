#include <vector>

int search(std::vector<int>& nums, int target)
{
    int leftWindowBoundary = 0;
    int rightWindowBoundary = nums.size() - 1;

    while (leftWindowBoundary <= rightWindowBoundary)
    {
        int currentMidPoint = leftWindowBoundary + (rightWindowBoundary - leftWindowBoundary) / 2;

        if (nums[currentMidPoint] == target)
            return currentMidPoint;

        if (target < nums[currentMidPoint])
            rightWindowBoundary = currentMidPoint - 1;
        else
            leftWindowBoundary = currentMidPoint + 1;
    }

    return -1;
}