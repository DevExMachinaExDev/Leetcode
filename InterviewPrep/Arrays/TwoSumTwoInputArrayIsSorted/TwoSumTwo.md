# Two sum Two - input is sorted discussion.

## Initial instincts
Another full disclosure... that will be three today when all is said and done... I already saw this question not too long ago and had the solution in the back of my mind so it did not take me long to recognise. Although attempting to remember what I thought the first time i saw this I think i recognised that it was likely some form of two pointer solution as when looking for two values in a sorted array that interact this is often the solution.

## twoSumTwoPointers
So it works off a rather simple principle. Since the array is sorted we know the lower values are at the far left and the higher at the far right. So we sum the furthest values and compare it to the expected value. If the result is too high we need a lower number so we move the right pointer left and if its too low we move the left pointer right. since you potentially only visit each element once it is O(N) time complexity with O(1) space complexity. A classic two pointer question.

## Thoughts
The only other relevant way to solve this I can think of is the standard hash map version that you solve with an unsorted vector, however there is a reason this information is sorted and it is a reminder to take advantage of sorted data structures where possible. I guess you could also use a modified binary search to solve this as well for O(nlogn) time since it would have worse time complexity and be far harder to implement it remains only a thought experiment.