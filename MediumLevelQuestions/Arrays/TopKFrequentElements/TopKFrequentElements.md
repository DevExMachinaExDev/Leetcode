## Top K frequent elements discussion  

# First instincts

My first thought here is that it would be next to impossible to do this both in a single pass and without storing each part of the information in some sort of map, array or bitmask. The general idea would have been to start off using a map to store the frequency of each element and then work with that.

# topKFrequentFirstAttempt  

This was really just a "get it down despite its memory usage" solution although I feel like it became the clearest solution. It works off the principle of creating a map of the number and its frequency, then in order to order the array by frequency we copy it into a vector of pairs and then use the sort function using the frequency. Then we read the top values back into it. This really just shows the basic steps and is technically O(n + m log m) due to the sorting step where m is the number of unique elements. In the worst case where all elements are unique this becomes O(n log n). Memory complexity is O(N) due to the frequency map and intermediary vector, but it does create unnecessary vectors. For showing how this can be solved simply this was a good first step for the next solution.

# topKFrequentBucketSort  

The good old bucket sort. Able to sort in O(n) time but usually at the expense of a lot of memory. This simply takes the highest frequency and then makes a vector that size to store all the values and then it reads this vector backwards starting with the largest into the vector we return. Its disadvantage is of course that the frequency range can be much larger than the number of distinct frequencies actually used, resulting in many empty buckets, but it is still useful. By avoiding the need to sort the frequencies directly it achieves O(n) time complexity with O(n) additional memory.

# Other solutions  

I thought of creating a "memoryless" version of this where it needs only a few integers for use in low-memory situations. In practicality however, this version would repeatedly need to recalculate frequencies by scanning the array again and again. Depending on the implementation this can degrade to O(k·n²) time complexity, and therefore O(n³) in the worst case when k approaches n. Every time it checked a current value it would need to check every other value as well, so the amount of repeated work becomes very large. While not practical, it is an interesting thought experiment nonetheless.