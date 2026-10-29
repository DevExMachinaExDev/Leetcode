# minimum size sub array sum discussion.

## First thoughts

I was fresh off Longest repeating character replacement for this one and honestly I figured it was probably the exact same solution for this one but in reverse. I realised though that the logic for the left pointer would have to be a little different and can not just be an if statement for this one as really the optimal solution is to find a big window first and then try to shrink as you go.

## minSubArrayLen
This uses a sliding window approach so really the outer loop just tracks the total and sees if it ever actually makes it over the desired max. If it doesn't then we stay at int max and return 0; The inner loop really is then about shrinking the window and seeing if there is a better solution so if it does not find one we carry on, if we do we shrink again to see if its even better still. It runs at O(N) although technically in a worst case it runs at O(2N) because the trailing pointer could check the entire array once more it also has O(1) space complexity as all it really uses is a few integers for tracking.

## Thoughts
This really only works because all the numbers are positive therefore when you remove an element from the start it is always lower and it is always higher when you move right, so its a little brittle. A brute force approach could definitely solve this for negative values, but it would be interesting to try and make that faster and much more difficult.

I also feel i only landed on the solution so quickly because of its proximity to my previous question.

