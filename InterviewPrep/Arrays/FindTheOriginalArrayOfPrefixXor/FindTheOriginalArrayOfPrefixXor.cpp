#include <vector>
#include <algorithm>

std::vector<int> findArrayFastest(std::vector<int>& pref) 
{
    int prefSize = pref.size();

    std::vector<int> toReturn;
    toReturn.reserve(prefSize);

    toReturn.push_back(pref[0]);

    for(int i = 1; i < prefSize; ++i)
    {
        toReturn.push_back(pref[i] ^ pref[i - 1]);
    }

    return toReturn;
}


std::vector<int> findArraySTLVersion(std::vector<int>& pref)
{
    std::vector<int> arr(pref.size());
    arr[0] = pref[0];

    std::transform(pref.begin() + 1, pref.end(), pref.begin(), arr.begin() + 1,
                   [](int a, int b){ return a ^ b; });

    return arr;
}
