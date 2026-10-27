# Longest substring without repeating characters discussion.

## First instincts

My first thoughts on this one was that it would be some form of sliding window solution with a bit map to track which elements had already been seen. I think i turned out to be half right with this because the problem is that using a bit mask does not actually help you to remember where the last time that element was seen which turned out to be a problem. When i tried to implement it i did not realise that by not tracking the positions it made it difficult to move the left pointer to the correct position.

## lengthOfLongestSubstring
The solution lands on the map solution which i felt was the most readable version of this problem although i was attempting to avoid using this expanding memory structure or all the extra space when there is a relatively small number of characters it could be but honestly Leetcode did not seem to like my bitmask version. It works by storing seen values in a map and if it finds the value in the map moving the left pointer to the position just after it and tracking how large the largest string attained is at it goes for O(n) time and O(k) space, where k is the number of distinct characters encountered in the string. In the worst case, this is O(min(n, c)), where c is the size of the character set.


## thoughts 
I really wanted to get that bitmask version working but i think the logic of removing whilst tracking the positions just won't work. I guess you could technically make it constant time by using an array of ints to track the positions instead of the map, but really since that is already using the maximum number of spaces you could argue it is no better for space but might be faster than all the hash lookups with it being a lookup table.

Another interesting note is that with the current version you could bow out of the loop early by checking if the currentUniqueStringSize + arrayNotTraversed < Largest found so it does not bother to complete the loop if it has already found it, but since that is additional overhead per loop and therefore probably slows down the worst case scenario just to speed up the  best case you could argue it is not the best solution, but is a possibility nonetheless.