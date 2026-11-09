#include <unordered_map>
#include <vector>
#include <string>

// Solution uses a binary search to retrieve the data and standard constructors and setters for the rest. Works in O(logN) time complexity and O(N) space complexity.
class TimeMap
{
    private:
        std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> timeBasedDataMap;

    public:
        TimeMap()
        {
        }

        void set(std::string key, std::string value, int timestamp)
        {
            timeBasedDataMap[key].push_back({timestamp, value});
        }

        std::string get(std::string key, int timestamp)
        {
            if (timeBasedDataMap.find(key) == timeBasedDataMap.end())
                return "";
            
            const auto& values = timeBasedDataMap[key];

            int left = 0;
            int right = values.size() - 1;

            std::string result = "";

            // Binary search for best element.
            while (left <= right)
            {
                int mid = left + (right - left) / 2;

                if (values[mid].first <= timestamp)
                {
                    result = values[mid].second;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }

            return result;
        }
};
