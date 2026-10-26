#include <vector>
#include <unordered_set>

int longestConsecutiveUnorderedSet(std::vector<int>& nums)
{
    // Populate a set as we are only interested in unique values.
    std::unordered_set<int> uniqueValues;

    for (int i : nums)
    {
        uniqueValues.insert(i);
    }

    int maxFound = 1;

    // Outer loop searches all unique values for starting values
    for (int i : uniqueValues)
    {
        // If starting value is found follow that track until done counting them.
        if (uniqueValues.find(i - 1) == uniqueValues.end())
        {
            int amountFound = 1;

            for (int j = i + 1; uniqueValues.find(j) != uniqueValues.end(); ++j)
            {
                ++amountFound;
            }

            if (amountFound > maxFound)
                maxFound = amountFound;
        }
    }

    return maxFound;
}