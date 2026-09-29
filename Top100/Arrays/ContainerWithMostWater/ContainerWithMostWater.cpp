#include <vector>
#include <Algorithm>

int maxAreaTwoPointer(const std::vector<int>& height)
{
    int leftPos  = 0;
    int rightPos = static_cast<int>(height.size()) - 1;

    int bestArea = 0;

    while (leftPos < rightPos)
    {
        int leftHeight  = height[leftPos];
        int rightHeight = height[rightPos];

        int containerHeight = (leftHeight < rightHeight) ? leftHeight : rightHeight;
        int containerWidth  = rightPos - leftPos;

        int area = containerHeight * containerWidth;
        if (area > bestArea)
            bestArea = area;

        if (leftHeight < rightHeight)
            ++leftPos;
        else
            --rightPos;
    }

    return bestArea;
}

