#include <vector>

int findClosestNumber(const std::vector<int>& nums)
{
    int closestValue = nums[0];
    int closestDistance = (closestValue >= 0) 
        ? closestValue 
        : -closestValue;

    for (int currentValue : nums)
    {
        int currentDistance = (currentValue >= 0) 
            ? currentValue 
            : -currentValue;

        if ((currentDistance < closestDistance) 
        || ((currentDistance == closestDistance) && (currentValue > closestValue)))
        {
            closestValue = currentValue;
            closestDistance = currentDistance;
        }
    }

    return closestValue;
}
