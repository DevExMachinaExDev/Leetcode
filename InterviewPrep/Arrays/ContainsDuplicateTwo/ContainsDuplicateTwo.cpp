#include <vector>
#include <unordered_map>

// Utilises a sliding window and a hash map to complete the problem having the map be either the size of k or nums depending which is smaller. O(n) time complexity O(min(n, k) space complexity.)
bool containsNearbyDuplicateSlidingWindow(std::vector<int>& nums, int k)
{
    if (nums.size() < 2)
        return false;

    std::unordered_map<int, int> found;

    // Run first to establish window size.
    for (int i = 0; i <= k && i < nums.size(); ++i)
    {
        if (found.find(nums[i]) != found.end())
        {
            if (i - found[nums[i]] <= k)
                return true;
        }

        found[nums[i]] = i;
    }

    int backPointer = 0;

    // Run second time with window that removes earlier elements.
    for (int i = k + 1; i < nums.size(); ++i)
    {
        found.erase(nums[backPointer]);
        backPointer++;

        if (found.find(nums[i]) != found.end())
        {
            if (i - found[nums[i]] <= k)
                return true;
        }

        found[nums[i]] = i;
    }

    return false;
}

// Brute force version. Would be used in situations where memory is a concern as it uses no additional memory but sacrifices time complexity. Time complexity O(n * min(n, k)). Space complexity O(1).
bool containsNearbyDuplicateBruteForce(std::vector<int>& nums, int k)
{
    for (int i = 0; i < nums.size() - 1; ++i)
    {
        for (int j = i + 1; j <= i + k && j < nums.size(); ++j)
        {
            if (nums[i] == nums[j])
                return true;
        }
    }

    return false;
}