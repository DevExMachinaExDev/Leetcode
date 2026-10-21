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