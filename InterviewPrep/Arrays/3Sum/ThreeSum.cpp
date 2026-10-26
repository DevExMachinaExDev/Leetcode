#include <vector>
#include <algorithm>

// Solution sorts the array and then goes through each element doing the standard two pointer search for the rest of the sum calculation O(n^2) time complexity and O(N) space complexity;
std::vector<std::vector<int>> threeSumSortedSearch(std::vector<int>& nums) 
{
    // Sort array
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    std::vector<std::vector<int>> toReturn;

    // Loop all values except last 2.
    for (int i = 0; i < sortedNums.size() - 2; ++i)
    {
        if (i > 0 && sortedNums[i] == sortedNums[i - 1])
            continue;

        // Do inner two sum calculation
        int j = i + 1;
        int k = sortedNums.size() - 1;

        while (j < k)
        {
            int currentSum = sortedNums[i] + sortedNums[j] + sortedNums[k];

            if (currentSum == 0)
            {            
                toReturn.push_back({sortedNums[i], sortedNums[j], sortedNums[k]});

                // Skip duplicates
                ++j;
                --k;

                int tempDuplicateChecker = sortedNums[j - 1];
                while (j < k && sortedNums[j] == tempDuplicateChecker)
                    ++j;

                tempDuplicateChecker = sortedNums[k + 1];
                while (j < k && sortedNums[k] == tempDuplicateChecker)
                    --k;
            }
            else if (currentSum > 0)
                --k;        
            else
                ++j;
        }
    }
    
    return toReturn;
}