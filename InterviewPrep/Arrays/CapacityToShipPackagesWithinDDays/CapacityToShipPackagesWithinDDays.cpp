#include <vector>

// Answer uses a binary search to search answers within the range. O(NlogS)
int shipWithinDays(std::vector<int>& weights, int days)
{
    int leftValue = 0;
    int rightValue = 0;

    // Find range of potential answers to check
    for (int weight : weights)
    {
        leftValue = std::max(leftValue, weight);
        rightValue += weight;
    }

    // Binary search potential answers.
    while (leftValue < rightValue)
    {
        int middle = leftValue + ((rightValue - leftValue) / 2);

        int daysNeeded = 1;
        int currentContainerFillAmount = 0;

        // Go through array filling containers counting days until we complete the array or exceed the max.
        for (int weight : weights)
        {
            if (currentContainerFillAmount + weight > middle)
            {
                daysNeeded++;
                currentContainerFillAmount = weight;

                if (daysNeeded > days)
                    break;
            }
            else
                currentContainerFillAmount += weight;
        }

        // Select side based on whether containers were filled or not.
        if (daysNeeded <= days)
            rightValue = middle;
        else
            leftValue = middle + 1;
    }

    return leftValue;
}