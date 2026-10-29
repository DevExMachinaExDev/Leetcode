#include <string>

bool checkInclusionSlidineWindowTrackingArrays(const std::string& s1, const std::string& s2)
{
    if (s1.size() > s2.size())
        return false;

    int expectedFrequency[26] = {};
    int currentWindowFrequency[26] = {};
    int sameCount = 26;

    // Populate expectedFrequency array
    for (char c : s1)
    {
        int location = c - 'a';

        if (expectedFrequency[location] == 0)
            --sameCount;

        ++expectedFrequency[location];
    }

    // Populate the first s1-sized window from s2.
    for (int i = 0; i < s1.size(); ++i)
    {
        int location = s2[i] - 'a';

        bool wasSame = expectedFrequency[location] == currentWindowFrequency[location];

        ++currentWindowFrequency[location];

        if (wasSame)
            --sameCount;

        if (expectedFrequency[location] == currentWindowFrequency[location])   
            ++sameCount;
        
    }

    // Check the initial window.
    if (sameCount == 26)
        return true;

    int leftPointer = 0;

    for (int rightPointer = s1.size(); rightPointer < s2.size(); ++rightPointer)
    {
        int rightLocation = s2[rightPointer] - 'a';
        int leftLocation = s2[leftPointer] - 'a';

        // Add the new character to the window.
        bool rightWasSame = expectedFrequency[rightLocation] == currentWindowFrequency[rightLocation];

        ++currentWindowFrequency[rightLocation];

        if (rightWasSame)
            --sameCount;

        if (expectedFrequency[rightLocation] == currentWindowFrequency[rightLocation])   
            ++sameCount;
        

        // Remove the old character from the window.
        bool leftWasSame = expectedFrequency[leftLocation] == currentWindowFrequency[leftLocation];

        --currentWindowFrequency[leftLocation];

        if (leftWasSame)
            --sameCount;

        if (expectedFrequency[leftLocation] == currentWindowFrequency[leftLocation])
            ++sameCount;
    

        ++leftPointer;

        if (sameCount == 26)
            return true;
    }

    return false;
}