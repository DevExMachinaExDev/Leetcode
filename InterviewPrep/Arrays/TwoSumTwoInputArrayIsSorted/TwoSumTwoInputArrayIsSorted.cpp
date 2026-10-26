#include <vector>

// Solution uses two pointers one on the left and one on the right and moves inwards depending how close to the sum it is which exploits that the array is sorted. O(N) time complexity. O(1) memory.
std::vector<int> twoSumTwoPointers(std::vector<int>& numbers, int target)
{
    int leftIndex = 0;
    int rightIndex = numbers.size() -1;

    std::vector<int> correctIndices {-1,-1};

    while(leftIndex < rightIndex)
    {
        int sum = numbers[leftIndex] + numbers[rightIndex];
        if(sum > target)
        {
            rightIndex--;
        }
        else if (sum < target) 
        {
            leftIndex++;
        }
        else
        {
            correctIndices[0] = leftIndex + 1;
            correctIndices[1] = rightIndex + 1;
            return correctIndices;
        }
    }

    return correctIndices;
} 