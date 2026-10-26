# Container with most water discussion. 

## Initial instinct

Third point of disclosure of the day. A lot of asterisks on today's performance haha. I have also solved this one in the past so the below is more me trying to remember my first thoughts on this question rather than outright remembering them from earlier in the day. I believe in my first attempt i did recognise this as a two pointer solution but my first attempt did not come from both ends of the array. I think I attempted to try and find the tallest i could find and then have the second pointer "run ahead" and try to find the best match and if it found another taller one that would become the new "left pointer" and it would run ahead again. The problem being that this greedy approach does not work reliably due to the occasional situation where the tallest is not part of the optimal answer. 

## maxAreaTwoPointers
I think I realised at a point that we can bring in the two pointers from either side and then just have each check try and sacrifice width for increased height somewhat implementing a simpler version of the greedy strategy but with simpler checks and move logic. This works at O(N) time complexity as each element is visited by either one of the pointers and O(1) space complexity for the variables used to store information about the best found values.

## Thoughts and alternatives
Its hard to consider how this could be improved upon honestly as I don't think that trading any extra memory could possibly make this algorithm any faster and it already is at O(1) space complexity. The only slight consideration would be that if we somehow had prior knowledge of the highest possible pillar we would be able to calculate whether a better value is even possible in certain circumstances and exit the loop quicker but that would coding for the best case scenario and slowing down the other cases slightly with the additional branching logic.