#include <vector>

// Solution uses the fact that one side in a binary search will always be sorted and checks the sorted side. O(logn) time complexity O(1) space complexity.
int search(std::vector<int>& nums, int target) 
{
    // Define our search window
    int leftSearchWindowBoundary = 0;
    int rightSearchWindowBoundary = nums.size() - 1;

    while (leftSearchWindowBoundary <= rightSearchWindowBoundary) 
    {
        int currentMiddle = leftSearchWindowBoundary + (rightSearchWindowBoundary - leftSearchWindowBoundary) / 2;

        if (nums[currentMiddle] == target) return currentMiddle;
        
        if (nums[leftSearchWindowBoundary] <= nums[currentMiddle]) // Left is sorted side.
        {
            // target in sorted left
            if (nums[leftSearchWindowBoundary] <= target && target < nums[currentMiddle])
                rightSearchWindowBoundary = currentMiddle - 1;
            else      
                leftSearchWindowBoundary = currentMiddle + 1;
        }
        else // right is sorted side
        {
            // target in sorted right
            if (nums[currentMiddle] < target && target <= nums[rightSearchWindowBoundary]) 
                leftSearchWindowBoundary = currentMiddle + 1;
            else 
                rightSearchWindowBoundary = currentMiddle - 1;          
        }
    }

    return -1;
}


