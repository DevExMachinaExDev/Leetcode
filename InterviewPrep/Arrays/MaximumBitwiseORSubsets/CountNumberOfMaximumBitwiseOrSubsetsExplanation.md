# Explanation of the answers for the question "Count Number of Maximum Bitwise-OR Subsets"  

## countMaxOrSubsetsHighPerformance  

This was an attempt at the highest performance solution. Given the problems need to visit every possible subset to determine its validity, its ideal time complexity must be O(2n). This version does a single pass at O(n) to collect the highest possible or operation which would always just be all elements OR'd together since an or will always at best be additive and at worst be equal. The second loop uses a bit mask to ensure that every possible iteration of the arrays variables is visited. The bit mask reflects whether or not each of the elements in the array will be included in this summation calculation which is then looped across to gather current sum (there are early exits added for when the sum is already found or there are no more array values in the current subset to add) Once it has found a set that matches or could not match it adds it to the total.  

This problem really taught me the value of using a bit set to explore every possible sub array.  

## countMaxOrSubsetsReadable  

This is really just the same version as above but using an iterator for the original accumulate to add readability.

Unfortunately due to the nature of the problem providing increased readability for the second loop is relatively impossible without massively changing how it works and its performance and thus the best version is this.  


### Additional thoughts  

Some things i would like to further explore would be further pruning unnecessary values. For example we could take our max value and find what its highest bit would be and then exclude subsets that do not at least include one of these values as they theoretically can never reach the max because the necessary furthest left bit will never be activated. The leetcode top question also did an interesting trick using recursion and pruning branches which had already met max values so that all values below are instantly added as they must be maximum, but given that I did not create that solution myself it has been ommitted.