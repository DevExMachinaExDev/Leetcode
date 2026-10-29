#include <vector>
#include <string>

// A long winded version that uses two arrays one of the expected frequency and one of the current frequency as well as a same count. O(s + p) time complexity
std::vector<int> findAnagramsSlidingWindowArrayComparison(std::string& s, std::string& p) 
{
    std::vector<int> result;

    if (s.size() < p.size())
        return result;

    // Set up comparison frequency array and keep it the same throughout
    int expectedFrequency[26] = {0};
    int sameCount = 26;

    for (char c : p)
    {
        int frequencyArrayLocation = c - 'a';

        if (expectedFrequency[frequencyArrayLocation] == 0)
            sameCount--;

        ++expectedFrequency[frequencyArrayLocation];
    }

    int currentWindowFrequency[26] = {0};

    // Populate first window
    for (int i = 0; i < p.size(); ++i)
    {
        int frequencyArrayLocation = s[i] - 'a';

        bool isLocationCurrentlySame =
            expectedFrequency[frequencyArrayLocation] ==
            currentWindowFrequency[frequencyArrayLocation];

        ++currentWindowFrequency[frequencyArrayLocation];

        if (isLocationCurrentlySame)
            sameCount--;

        if (expectedFrequency[frequencyArrayLocation] ==
            currentWindowFrequency[frequencyArrayLocation])
        {
            sameCount++;
        }
    }

    if (sameCount == 26)
        result.push_back(0);

    int leftPointer = 0;

    for (int rightPointer = p.size(); rightPointer < s.size(); ++rightPointer)
    {
        int rightLocation = s[rightPointer] - 'a';
        int leftLocation = s[leftPointer] - 'a';

        // Add new character to window
        bool rightWasSame = expectedFrequency[rightLocation] == currentWindowFrequency[rightLocation];

        ++currentWindowFrequency[rightLocation];

        if (rightWasSame)
            sameCount--;

        if (expectedFrequency[rightLocation] == currentWindowFrequency[rightLocation])
            sameCount++;
        

        // Remove old character from window
        bool leftWasSame = expectedFrequency[leftLocation] == currentWindowFrequency[leftLocation];

        --currentWindowFrequency[leftLocation];

        if (leftWasSame)
            sameCount--;

        if (expectedFrequency[leftLocation] == currentWindowFrequency[leftLocation])
            sameCount++;
        

        ++leftPointer;

        if (sameCount == 26)
            result.push_back(leftPointer);
    }

    return result;
}