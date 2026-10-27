# Maximum average sub array discussiong.

## First instincts
My first thoughts for this were that this is a sliding window problem as the description practically begs you to use a sliding window (and after yesterday thinking that questions can lead you in the wrong direction). So i thought about how we could do a window of finding a sum (the average can be found at the end for a lower number of total calculations). 

## maximumAverageSubArraySlidingWindow.

The key thing here is not the sliding window but the not allowing the problem to become O(N^2) time by constantly recalculationg the total sum of all the elements within the window. Luckily this really is mathematically easy for this questions as the sum is all the elements added together so when we add a new value we simply add the right most value from the total that has already been calculated and we take the left most value from it as it is no longer part of the total sum. This was a relatively easy question and it comes in at O(N) time complexity and O(1) space complexity from the few doubles and longs etc used.

## Thoughts
A tricky one to give different approaches for because it seems like the optimal solution jumps out on this question, but as already mentioned you could do the far worse brute force version of calculating every total every time for O(N)