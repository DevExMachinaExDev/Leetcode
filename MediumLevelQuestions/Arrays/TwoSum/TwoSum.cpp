# include <unordered_map>
# include <vector>

// Fastest version that uses extra space for a map. O(N) speed O(N) complexity;
std::vector<int> twoSumSpeed(std::vector<int>& nums, int target)
{
    std::vector<int> twoSum{0, 0};
    std::unordered_map<int, int> currentlySeen;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (currentlySeen.find(nums[i]) != currentlySeen.end())
        {
            twoSum[0] = currentlySeen[nums[i]];
            twoSum[1] = i;
            break;
        }

        currentlySeen[target - nums[i]] = i;
    }

    return twoSum;
}

// Version that uses no extra memory other than the returned vector but has extra time complexity. O(n^2) time complexity O(1) space.
std::vector<int> twoSumMemory(std::vector<int>& nums, int target)
{
    std::vector<int> twoSum {0, 0};

    for(int i = 0; i < nums.size() - 1; ++i)
    {
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                twoSum[0] = i;
                twoSum[1] = j;
                break;
            } 
        }
    }

    return twoSum;
}