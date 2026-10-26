#include <vector>

// Solution works by keeping track of where the last integer should be and placing it there and then populating the rest with zeroes. O(N) time complexity O(1) space.
void moveZeroesTwoPointer(std::vector<int>& nums)
{
    int currentIntegerPosition = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
        {
            nums[currentIntegerPosition] = nums[i];
            ++currentIntegerPosition;
        }
    }

    for (int i = currentIntegerPosition; i < nums.size(); ++i)
    {
        nums[i] = 0;
    }
}