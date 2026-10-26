#include <vector>
#include <numeric>
#include <functional>

int countMaxOrSubsetsHighPerformance(std::vector<int>& nums)
{
    int n = nums.size();

    // Loop finds the max subset.
    int maxOR = 0;
    for (int x : nums)
        maxOR |= x;

    int count = 0;

    // Loop checks all subsets using a bit mask.
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int tempMask = mask;
        int index = 0;
        int currentCheck = 0;

        
        while (tempMask > 0)
        {
            if (tempMask & 1)
                currentCheck |= nums[index];


            if (currentCheck == maxOR)
                break;

            tempMask >>= 1;
            index++;
        }

        if (currentCheck == maxOR)
            count++;
    }

    return count;
}

int countMaxOrSubsetsReadable(std::vector<int>& nums)
{
    int n = nums.size();

    // Loop finds the max subset.
    int maxOR = accumulate(nums.begin(), nums.end(), 0, std::bit_or<>());

    int count = 0;

    // Loop checks all subsets using a bit mask.
    for (int mask = 1; mask < (1 << n); mask++)
    {
        int tempMask = mask;
        int index = 0;
        int currentCheck = 0;

        
        while (tempMask > 0)
        {
            if (tempMask & 1)
                currentCheck |= nums[index];


            if (currentCheck == maxOR)
                break;

            tempMask >>= 1;
            index++;
        }

        if (currentCheck == maxOR)
            count++;
    }

    return count;
}