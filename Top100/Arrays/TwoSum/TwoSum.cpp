#include <vector>
#include <unordered_map>

std::vector<int> twoSumBruteForce(std::vector<int>& nums, int target) 
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                return { i, j };
        }
    }

    return {};
}

std::vector<int> twoSumHashMap(std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> seen;
    seen.reserve(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        int value = nums[i];

        auto it = seen.find(value);
        if (it != seen.end())
        {
            return { it->second, i };
        }

        seen[target - value] = i;
    }

    return {};
}


