#include <vector>

double findMaxAverage(std::vector<int>& nums, int k) 
{
    // Find sum of the first window
    long long windowSum = 0;
    for (int i = 0; i < k; i++) 
    {
        windowSum += nums[i];
    }

    // Slide along takings left most value and adding new right most.
    long long maxSum = windowSum;

    for (int i = k; i < nums.size(); i++) 
    {
        windowSum += nums[i];      
        windowSum -= nums[i - k];   

        maxSum = std::max(maxSum, windowSum);
    }

    return (double)maxSum / k;
}