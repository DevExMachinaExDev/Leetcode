#include <climits>
#include <vector>

// Sliding window approach adds to the total when moving right then moves left whilst subtracting on inner loop. O(N)time complexity and O(1) space complexity.
int minSubArrayLen(int target, std::vector<int>& nums)
{
    int leftPointer = 0;
    int currentSumTotal = 0;
    int smallestFound = INT_MAX;

    for (int rightPointer = 0; rightPointer < nums.size(); ++rightPointer)
    {
        currentSumTotal += nums[rightPointer];

        while (currentSumTotal >= target)
        {
            smallestFound = std::min(smallestFound, rightPointer - leftPointer + 1);

            currentSumTotal -= nums[leftPointer];
            ++leftPointer;
        }
    }

    return smallestFound == INT_MAX ? 0 : smallestFound;
}