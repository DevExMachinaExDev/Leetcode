# Three sum discussion

## First instincts

So upon first seeing this problem I thought immediately about using a hash set to solve this issue so that you can check it in O(N²) by looking at each of the individual elements and then checking all other elements in the array against it and looking to see if the required third value is in the set, but this has the problem that if you have already found the value in the array and you need two of them, for example (8, -4, -4), how do you ensure it is not getting used twice? I guessed that you could use a map to find the count of each value and then once you have done the first "i" element you could decrement its total from the map or completely remove it if it reaches zero and do checks for each of the other two every time to see if there are enough left or not.

But essentially it was a way of doing it in O(N²), or so I thought, until I realised that you can't have duplicate triplets so you would have to sort every single vector and then put them in a set to prevent this from happening, and then all that has to be copied back over... AAAAAAAAAAAAAAAAHHHHHH! You get the picture.



## threeSumSortedSearch

The sorting gave me an idea though that we could sort the array and then use the approach from the 2 Sum II problem that uses two pointers to find the solution. Essentially this solution fixes the first number and then does a two-pointer search coming in from either side, adjusting the pointers depending on whether the current sum is too high or too low. It runs in O(N²) as it effectively scans most of the remaining array for each element.



## Thoughts

I really kind of lucked out with this one that I had previously looked at the 2 Sum II solution, but I really went down a rabbit hole trying to use the wrong toolset of maps for this problem and ended up taking longer than expected. A reminder, perhaps, that if a solution is getting overly complex then you may need to step back and think about a different approach.