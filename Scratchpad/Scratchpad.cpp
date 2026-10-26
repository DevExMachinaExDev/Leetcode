#include<vector>

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