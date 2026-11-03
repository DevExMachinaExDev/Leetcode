#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
#include <string>

std::vector<int> productExceptSelf(std::vector<int>& nums)
{
    int n = nums.size();
    std::vector<int> toReturn(n, 1);

    int product = 1;

    // products to the left.
    for (int i = 0; i < n; ++i)
    {
        toReturn[i] = product;
        product *= nums[i];
    }

    product = 1;

    // products to the right.
    for (int i = n - 1; i >= 0; --i)
    {
        toReturn[i] *= product;
        product *= nums[i];
    }

    return toReturn;
}

int maxArea(const std::vector<int>& height)
{
    // Variable init
    int highestLeft = 0;
    int highestRight = 0;
    int largestArea = 0;
    int horizontalDistance = height.size() -1;

    // Pointer init
    int leftPointer = 0;
    int rightPointer = height.size() -1;
    
    while (leftPointer < rightPointer)
    {
        int currentLeft = height[leftPointer];
        int currentRight = height[rightPointer];

        int currentLowestPillar = std::min(currentLeft, currentRight);
        int currentArea = currentLowestPillar * (leftPointer - rightPointer);

        largestArea = std::max(currentArea, largestArea);

        highestLeft = std::max(currentLeft, highestLeft);
        highestRight = std::max(currentRight, highestRight);

        if (currentLeft > currentRight)
         --rightPointer;
        else ++leftPointer;
    }


    return largestArea;
}

// Best time to buy and sell stock revision.
int maxProfit(std::vector<int>& prices) 
{
    int bestFound = 0;
    int currentLowest = prices[0];
    int currentHighest = 0;

    for(int i = 0; i < prices.size(); ++i)
    {
        currentHighest = std::max(currentHighest, prices[i]);

        if(prices[i] < currentLowest)
        {
            currentLowest = prices[i];
            currentHighest = currentLowest;
        }

        bestFound = std::max(bestFound, (currentHighest - currentLowest));
    }

    return bestFound;
}

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, int> found;

    std::vector<int> toReturn {-1, -1};

    for (int i = 0; i < nums.size(); ++i)
    {
        if(found.find(target - nums[i]) != found.end())
        {
            toReturn[0] = found[target - nums[i]];
            toReturn[1] = i;
            break;
        }

        found[nums[i]] = i;
    }

    return toReturn;
}

int lengthOfLongestSubstring(std::string s)
{
    std::unordered_map<char, int> lastSeenChars;

    int leftPointer = 0;
    int longestFoundSequence = 0;

    for (int rightPointer = 0; rightPointer < s.size(); ++rightPointer)
    {
        char currentTargetChar = s[rightPointer];

        if (lastSeenChars.count(currentTargetChar) > 0)
            leftPointer = std::max(leftPointer, lastSeenChars[rightPointer] + 1);
        
        lastSeenChars[currentTargetChar] = rightPointer;
        longestFoundSequence = std::max(longestFoundSequence, rightPointer - leftPointer + 1);
    }

    return longestFoundSequence;
}


int characterReplacement(std::string s, int k) 
{
    int frequencies[26] = {0};

    int leftPointer = 0;
    int maxFrequency = 0;
    int longestStringFound = 0;

    for (int rightPointer = 0; rightPointer < s.size(); ++rightPointer)
    {
        int rightFrequencyIndex = s[rightPointer] - 'A';
        frequencies[rightFrequencyIndex]++;
        maxFrequency = std::max(maxFrequency, frequencies[rightFrequencyIndex]);

        // Branchless left Move decision
        int nonMaximumCharNumber = ((rightPointer - leftPointer + 1) - maxFrequency);
        int leftPointerShrinkAmount = nonMaximumCharNumber > k; // Always 1 or 0;
        frequencies[s[leftPointer] - 'A'] -= leftPointerShrinkAmount;
        leftPointer += leftPointerShrinkAmount;
        

        longestStringFound = std::max(longestStringFound, rightPointer - leftPointer + 1);
    }

    return longestStringFound;
}


int containerWithMostWater(const std::vector<int>& height)
{
    int leftPointer = 0;
    int rightPointer = height.size() - 1;

    int bestArea = 0;

    while (rightPointer > leftPointer)
    {
        int leftHeight = height[leftPointer];
        int rightHeight = height[rightPointer];
        int lowestPillar = std::min(leftHeight, rightHeight);
        int area = lowestPillar * (rightPointer - leftPointer);
        bestArea = std::max(bestArea, area);

        if (leftHeight < rightHeight)
            leftPointer++;
        else
            rightPointer--;
    }

    return bestArea;
}

int search(std::vector<int>& nums, int target)
{
    int leftWindowBoundary = 0;
    int rightWindowBoundary = nums.size() - 1;

    while (leftWindowBoundary <= rightWindowBoundary)
    {
        int currentWindowSize = rightWindowBoundary - leftWindowBoundary;
        int targetElement = leftWindowBoundary + (currentWindowSize / 2);
        int currentTargetValue = nums[targetElement];

        if (target == currentTargetValue)
            return targetElement;
        else if (target < currentTargetValue)
            rightWindowBoundary = targetElement - 1;   
        else if (target > currentTargetValue)
            leftWindowBoundary = targetElement + 1;
    }

    return -1;
}

double findMaxAverage(std::vector<int>& nums, int k) 
{
    long long windowCurrentSum = 0;
    
    for(int i = 0; i < k; i++) 
    {
        windowCurrentSum += nums[i];
    }
    
    long long currentHighest = windowCurrentSum;
    
    for (int rightPointer = k; rightPointer < nums.size(); ++rightPointer) 
    {
        windowCurrentSum += nums[rightPointer] - nums[rightPointer - k];
        currentHighest = std::max(currentHighest, windowCurrentSum);
    }
    
    return static_cast<double>(currentHighest) / k;
}

int searchInRotatedSortedArray(std::vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size() - 1;
    int middle;

    while (left <= right)
    {
        middle = left + ((right - left) / 2);

        int leftValue = nums[left];
        int midValue = nums[middle];
        int rightValue = nums[right];

        if (midValue == target)
            return middle;
        if (leftValue == target)
            return left;
        if (rightValue == target)
            return right;

        // Check left organised
        if(leftValue <= midValue)
        {
            if(target >= leftValue && target <= midValue)
                right = middle - 1;          
            else
                left = middle + 1;
        }
        else // Check right
        {
            if(target > midValue && target <= rightValue)
                left = middle + 1;  
            else
                right = middle - 1;
        }
    }

    return -1;
}

std::string minWindow(std::string s, std::string t)
{
    int tMap[128] = {};
    int sMap[128] = {};
    int uniqueValues = 0;

    // populate tMap
    for (int i = 0; i < t.size(); ++i)
    {
        int current = t[i];

        if (tMap[current] == 0)
            uniqueValues++;

        tMap[current]++;
    }

    int substringLeftPointer = 0;
    int substringRightPointer = 0;
    int smallestFound = INT_MAX;

    int leftPointer = 0;

    for (int rightPointer = 0; rightPointer < s.size(); ++rightPointer)
    {
        char currentCharMapLocation = s[rightPointer];

        if (tMap[currentCharMapLocation] == 0)
            continue;

        sMap[currentCharMapLocation]++;

        if (sMap[currentCharMapLocation] == tMap[currentCharMapLocation])
            uniqueValues--;

        if (uniqueValues > 0)
            continue;

        // Move left pointer
        while (leftPointer <= rightPointer)
        {
            if (smallestFound > rightPointer - leftPointer + 1)
            {
                smallestFound = rightPointer - leftPointer + 1;
                substringLeftPointer = leftPointer;
                substringRightPointer = rightPointer;
            }

            char currentLeftChar = s[leftPointer];

            if (tMap[currentLeftChar] == 0)
            {
                leftPointer++;
                continue;
            }

            sMap[currentLeftChar]--;

            if (sMap[currentLeftChar] < tMap[currentLeftChar])
            {
                uniqueValues++;
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

