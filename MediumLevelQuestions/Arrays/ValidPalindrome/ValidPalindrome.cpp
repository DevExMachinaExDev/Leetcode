#include <string>

// Solution uses two pointers and skips values not needed. Runs at O(n) with O(1) memory.
bool isPalindromeTwoPointer(std::string& s)
{
    int j = s.size() - 1;

    for (int i = 0; i < j; ++i)
    {
        if (!std::isalnum(s[i]))
            continue;

        while (j > i && !std::isalnum(s[j]))
        {
            --j;
        }

        if (std::tolower(s[i]) != std::tolower(s[j]))
        {
            return false;
        }

        --j;
    }

    return true;
}