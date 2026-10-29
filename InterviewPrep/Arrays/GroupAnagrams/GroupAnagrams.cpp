#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> groups;

    for (std::string word : strs)
    {
        std::string key = word;
        std::sort(key.begin(), key.end());

        groups[key].push_back(word);
    }

    std::vector<std::vector<std::string>> result;

    for (std::pair<const std::string, std::vector<std::string>>& entry : groups)
    {
        result.push_back(entry.second);
    }

    return result;
}

// Solution creates hashes that are unique to the string by creating a frequency table and building a string from it. O(nk) where k is the average string length and O(nk) memory.
std::vector<std::vector<std::string>> groupAnagramsUniqueHash(std::vector<std::string>& strs)
{
    std::unordered_map<std::string, std::vector<std::string>> groups;

    for (const std::string& word : strs)
    {
        // Create count array
        int counts[26] = {};

        for (char c : word)
        {
            ++counts[c - 'a'];
        }

        // Build a unique key from the character frequencies
        std::string key;
        for (int count : counts)
        {
            key += '#';
            key += std::to_string(count);
        }

        groups[key].push_back(word);
    }

    std::vector<std::vector<std::string>> result;

    for (std::pair<const std::string, std::vector<std::string>>& entry : groups)
    {
        result.push_back(entry.second);
    }

    return result;
}