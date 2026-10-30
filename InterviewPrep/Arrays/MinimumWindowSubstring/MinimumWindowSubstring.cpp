#include <climits>
#include <string>
#include <unordered_map>

// Solution uses two hash maps to compare to one another and a sliding window which moves the left whenever it contains a valid string until no longer valide O(m + n) time complexity. O(1) spaces (maps will always be under 52).
std::string minWindowHashMap(std::string s, std::string t)
{
    // Populate tMap with frequencies and sMap with 0s
    std::unordered_map<char, int> tMap;
    std::unordered_map<char, int> sMap;

    for(char c : t)
    {
        if(tMap.count(c))
            tMap[c]++;
        else
        {
            tMap[c] = 1;
            sMap[c] = 0;
        }
    }

    int substringLeftPointer = 0;
    int substringRightPointer = 0;
    int smallestFound = INT_MAX;

    int expectedSameValues = t.size();
    int leftPointer = 0;

    for (int rightPointer = 0; rightPointer < s.size(); ++rightPointer)
    {
        char currentRightChar = s[rightPointer];

        if(!tMap.count(currentRightChar)) // Ignore if irrelevant.
            continue;

        // Update sMap and restart loop if maps do not match.
        if (sMap[currentRightChar] < tMap[currentRightChar])
            expectedSameValues--;
        sMap[currentRightChar]++;

        if (expectedSameValues > 0)
            continue;

        // Move left pointer
        while (leftPointer <= rightPointer)
        {
            // Update smallest found
            if (smallestFound > rightPointer - leftPointer)
            {
                smallestFound = rightPointer - leftPointer;
                substringLeftPointer = leftPointer;
                substringRightPointer = rightPointer;
            }

            char currentLeftChar = s[leftPointer];

            // Exit early if value is not relevant
            if(!tMap.count(currentLeftChar))
            {
                leftPointer++;
                continue;
            }

            // Check if we have removed a value such that it no longer matches. If so stop moving left pointer.
            sMap[currentLeftChar]--;

            if (sMap[currentLeftChar] < tMap[currentLeftChar])
            {
                expectedSameValues++;
                leftPointer++;
                break;
            }

            leftPointer++;
        }
    }

    if (smallestFound == INT_MAX)
        return "";

    return s.substr(substringLeftPointer,substringRightPointer - substringLeftPointer + 1);
}
