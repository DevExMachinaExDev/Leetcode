# Maximum sub array answers explanation.

## maxSubArrayArrayTraversal

This version does a simple array traversal using branching conditional logic to determine whether or not we reached the maximum amount so far. It completes in O(N) time complexity because it traverses the array once and it has O(1) space complexity storing only two integer variables.

## maxSubArrayBranchless

This version uses similar logic to the first problem but it mathematically calculates the current maximum values rather than using if statements. This is to prevent branching logic in the CPU causing partial branch traversals which would slow the algorithm down. This is a minor optimisation but should gain additional performance.