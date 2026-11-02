#include <vector>

// Solution uses two binary searches, one to find the correct row and one to find the correct element in the row. Runs at O(m + n) has space complexity O(1).
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
    int leftWindowBoundary = 0;
    int rightWindowBoundary = matrix.size() - 1;
    int arrayToTraverse = 0;

    while (leftWindowBoundary <= rightWindowBoundary)
    {
        int currentWindowSize = rightWindowBoundary - leftWindowBoundary;
        int targetElement = leftWindowBoundary + (currentWindowSize / 2);
        int currentTargetValue = matrix[targetElement][0];

        if (target == currentTargetValue)
            return true;

        if (targetElement == matrix.size() - 1)
        {
            arrayToTraverse = targetElement;
            break;
        }

        int nextTargetValue = matrix[targetElement + 1][0];

        if (target > currentTargetValue)
        {
            if (target == nextTargetValue)
                return true;
            else if (target < nextTargetValue)
            {
                arrayToTraverse = targetElement;
                break;
            }
            else
            {
                leftWindowBoundary = targetElement + 1;
            }
        }
        else
        {
            rightWindowBoundary = targetElement - 1;
        }
    }

    leftWindowBoundary = 0;
    rightWindowBoundary = matrix[arrayToTraverse].size() - 1;

    while (leftWindowBoundary <= rightWindowBoundary)
    {
        int currentWindowSize = rightWindowBoundary - leftWindowBoundary;
        int targetElement = leftWindowBoundary + (currentWindowSize / 2);
        int currentTargetValue = matrix[arrayToTraverse][targetElement];

        if (target == currentTargetValue)
            return true;
        else if (target < currentTargetValue)
            rightWindowBoundary = targetElement - 1;
        else
            leftWindowBoundary = targetElement + 1;
    }

    return false;
}