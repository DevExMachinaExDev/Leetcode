#include <vector>
#include <unordered_map>

// Typical voting algorithm. This is the best solution with O(n) time complexity and very little O(1) memory. 
int majorityElementVoting(std::vector<int>& nums) 
{
    int currentBest = nums[0];
    int currentBestCount = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] == currentBest)
        {
            currentBestCount++;
        }
        else
        {
            currentBestCount--;

            if (currentBestCount == 0)
            {
                currentBest = nums[i];
                currentBestCount = 1;
            }
        }
    }

    return currentBest;
}

// This approach is objectively worse than the above but it is the first one created somwhat naively. It has O(n) time complexity but uses O(n) memory.
int majorityElementHashMap(std::vector<int>& nums) 
{
    int targetOccurences = nums.size() / 2;
    std::unordered_map<int, int> found{};

    for (int i : nums)
    {
        found[i]++;

        if (found[i] > targetOccurences)
            return i;
    }

    return -1;
}

