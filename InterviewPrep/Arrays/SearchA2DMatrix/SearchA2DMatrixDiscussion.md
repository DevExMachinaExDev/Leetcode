# Search a 2D matrix discussion

## First instincts

The brute force approach first popped into mind where you could easily run through the entire set of vectors checking the first element and checking if the next one is higher than what we are looking for and then once we are on the correct array start searching the current one sequentially (you could even calculate how many array elements are in the array and the integer and do a sligth optimisation where you run the array backwards if it is only possible for that element to be in the second half of the array.) 
This of course is all sort of baloney however because really we need to do this in O(log(m*n)) and we are given sorted numbers for a reason here. I realised then that this was a binary search question through this.

## SearchMatrix

So I decided to do this in the simplest way I could think combining the methods discussed above. So we instead use a binary search to find the correct row for O (logm) and then when we have the correct row we use a binary search to find the element for O(logn) giving what is technically within the solution parameters O(log m * n). See the discussion below.

## Thoughts

This is a question I looked up the correct solution after the fact because it did not sit right with me that my code is a little needlessly complex and I found that the solution is to treat the entire thing like a single flat array and then do a single binary search meaning you do not have to do the first binary search that my version does. I'll be honest here, I think I would have gotten this had I read the question more carefully as the optimal solution only works if all of the inner vectors are the same size which is in the requirements for the question. It does in some ways mean that my solution whilst a little slower is technically more robust because it does not rely on fixed array sizes for the entire matrix as this one does. However the added level of complexity made this much easier to get aspects wrong and I spent a little time in the maze of off by one errors that my solution produces. On reflection I do think that mine is what i would push to production unless we were absolutely 100% certain that we knew the size was consistent.