#include <string>
#include <unordered_map>

// Solution uses a map to store the last locations that something was seen and uses a sliding window approach. 
int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, int> lastSeen;

    int leftPointer = 0;
    int longest = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        char current = s[right];

        if (lastSeen.count(current))
        {
            leftPointer = std::max(leftPointer, lastSeen[current] + 1);
        }

        lastSeen[current] = right;
        longest = std::max(longest, right - leftPointer + 1);
    }

    return longest;
}