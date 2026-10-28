#include <string>

// Solution uses a sliding window and a reference array that only grows if possible. O(N) time complexity and O(1 space complexity.)
int characterReplacementSlidingWindow(std::string s, int k) 
{
    int freq[26] {0};

    int leftPointer = 0;
    int maxFreq = 0;
    int longestFound = 0;

    for (int rightPointer = 0; rightPointer < s.size(); rightPointer++) 
    {
        int idx = s[rightPointer] - 'A';

        freq[idx]++;
        maxFreq = std::max(maxFreq, freq[idx]);

        // Move left pointer if window cannot grow.
        if ((rightPointer - leftPointer + 1) - maxFreq > k)
        {
            freq[s[leftPointer] - 'A']--;
            leftPointer++;
        }

        longestFound = std::max(longestFound, rightPointer - leftPointer + 1);
    }

    return longestFound;
}