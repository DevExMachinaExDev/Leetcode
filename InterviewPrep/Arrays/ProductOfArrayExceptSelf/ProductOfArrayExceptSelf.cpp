#include <vector>

// Looked up how to do a divide without dividing and came up with this solution. Does not run in the allocated O(n) time but is how i would do this
std::vector<int> productExceptSelfHomeMadeDivide(std::vector<int>& nums) 
{
    // Find total product loop
    int totalProduct = 1;

    for(int i : nums)
    {
        totalProduct *= i;
    }
    
    // Create new array
    std::vector<int> productsExceptSelf;
    productsExceptSelf.reserve(nums.size());

    // Use maths to populate with product - value
    for(int i = 0; i < nums.size(); ++i)
    {
        int divisionCounter = 0;
        int dividee = totalProduct;
        int divider = nums[i];
        while(dividee >= divider)
        {
            dividee -= divider;
            divisionCounter++;
        }

        nums[i] = divisionCounter;
    }

    return productsExceptSelf;
}

// Correct solution. Runs at O(N) time using two runs and O(N) memory which is required for the vector to return but uses minimal additional memory.
std::vector<int> productExceptSelfTwoRuns(std::vector<int>& nums)
{
    std::vector<int> toReturn(nums.size(), 1);

    // First pass finds product of all to the left of value.
    int leftRunningProduct = 1;
    for (int i = 0; i < nums.size(); ++i)
    {
        toReturn[i] = leftRunningProduct;
        leftRunningProduct *= nums[i];
    }

    // Second pass finds product of all to the right of the value.
    int rightRunningProduct = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        toReturn[i] *= rightRunningProduct;
        rightRunningProduct *= nums[i];
    }

    return toReturn;
}