#include <vector>
#include <unordered_map>
#include <algorithm>

// Simple solution using sorting. First attempt but suffers from O(nlogn) sorting algorithm and O(N) space complexity (more than just a single extra array as well)
std::vector<int> topKFrequentFirstAttempt(std::vector<int>& nums, int k)
{
    // Populate frequency map
    std::unordered_map<int, int> frequencyMap;

    for (int num : nums)
    {
        frequencyMap[num]++;
    }

    // Store frequency map in sortable vector.
    std::vector<std::pair<int, int>> frequenciesAsVector;
    frequenciesAsVector.reserve(frequencyMap.size());

    for (std::pair<const int, int>& entry : frequencyMap)
    {
        frequenciesAsVector.push_back({entry.first, entry.second});
    }

    // Sort entire frequency vector.
    std::sort(frequenciesAsVector.begin(), frequenciesAsVector.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.second > b.second;
    });

    // Use only k elements for result
    std::vector<int> result;

    for (int i = 0; i < k; ++i)
    {
        result.push_back(frequenciesAsVector[i].first);
    }

    return result;
}

// Fastest found solution with the bucket sort algorithm. Has the best time complexity at O(N) bust suffers again from O(N).
std::vector<int> topKFrequentBucketSort(std::vector<int>& nums, int k)
{
    // Populate frequency map
    std::unordered_map<int, int> frequency;
    int highestFrequency = 0;

    for (int num : nums)
    {
        frequency[num]++;

        if (frequency[num] > highestFrequency)
            highestFrequency = frequency[num];
    }

    // Populate bucket for sorting.
    std::vector<std::vector<int>> buckets(highestFrequency + 1);
    for (std::pair<const int, int>& entry : frequency)
    {
        buckets[entry.second].push_back(entry.first);
    }

    // Add sorted values to return vector.
    std::vector<int> toReturn;
    toReturn.reserve(k);

    for (int i = highestFrequency; i >= 0; --i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            toReturn.push_back(buckets[i][j]);

            if (toReturn.size() >= k)
                return toReturn;
        }
    }

    return toReturn;
}

