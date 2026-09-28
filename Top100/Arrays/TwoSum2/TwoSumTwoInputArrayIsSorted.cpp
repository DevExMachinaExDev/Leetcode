#include <vector>

std::vector<int> twoSumTwoPointer(std::vector<int>& numbers, int target) 
{
    int leftIndex = 0;
    int rightIndex = numbers.size() - 1;

    while (leftIndex < rightIndex)
    {
        int sum = numbers[leftIndex] + numbers[rightIndex];
        if (sum == target)
            return { leftIndex + 1, rightIndex + 1 };
        else if (sum < target)
            leftIndex++; 
        else
            rightIndex--;
    }

    return {};
}
