#include <vector>
#include <algorithm>
#include <climits>

int maxSubArrayArrayTraversal(std::vector<int>& nums) 
{
    int maxReached = INT_MIN;
    int currentSum = 0;
    
    for (int i = 0; i < nums.size(); ++i) 
    {
        currentSum += nums[i];
        if (currentSum > maxReached)
            maxReached = currentSum;
        
        if (currentSum < 0)
            currentSum = 0;
    }
    return maxReached;
}

int maxSubArrayBranchless(const std::vector<int>& nums)
{
    int current = 0;
    int best = INT_MIN;

    for (int x : nums)
    {
        current = std::max(x, current + x);
        best = std::max(best, current);
    }

    return best;
}