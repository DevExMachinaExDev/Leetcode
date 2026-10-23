#include <vector>

// Solution uses two pointers moving towards the middle keeping the larger heights where possible (greedy) and checking if the best area is achieved. O(N) time complexity. O(1) space complexity.
int maxArea(const std::vector<int>& height)
{
    int leftPointerPosition  = 0;
    int rightPointerPosition = height.size() - 1;

    int bestArea = 0;

    while (leftPointerPosition < rightPointerPosition)
    {
        // Get current containers dimensions
        int currentLeftHeight  = height[leftPointerPosition];
        int currentRightHeight = height[rightPointerPosition];

        int currentContainerHeight = (currentLeftHeight < currentRightHeight) 
            ? currentLeftHeight 
            : currentRightHeight;
        int currentContainerWidth = rightPointerPosition - leftPointerPosition;
        int currentContainerArea = currentContainerHeight * currentContainerWidth;

        // Update if better
        if (currentContainerArea > bestArea)
            bestArea = currentContainerArea;

        // Move pointer greedily to better solution.
        if (currentLeftHeight < currentRightHeight)
            ++leftPointerPosition;
        else
            --rightPointerPosition;
    }

    return bestArea;
}