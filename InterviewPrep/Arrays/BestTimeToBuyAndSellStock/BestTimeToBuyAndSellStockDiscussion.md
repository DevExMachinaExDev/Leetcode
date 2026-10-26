# Best time to buy and sell stock Discussion.

## First instincts  

Perhaps it was due to the "Container With Most Water" solution from the other day, but I went a little off track with this question today as well. I immediately noticed that it was a two-pointer problem, but I spent a good long while trying to figure out how I could get a pointer to come in from the left and the right and still have the best values. The problem being: when exactly do you move the pointers? How do you know you have the best right and left values and prevent backtracking?

## maxProfit  

When I started to rethink it as a single-pass solution, that's when it clicked. All you need to do is find the lowest value seen so far, store it, and then whenever you find a higher value check if it beats your current best profit. The only real caveat is that the higher value has to come after the low value, so you cannot simply track the global highest and lowest values independently.

This uses O(N) time complexity as it is a single pass and only O(1) space complexity. It serves as a reminder that two-pointer problems can involve both pointers moving through the array together and do not always have to come from opposite ends.

## Thoughts  

A bit of a theme today of going down the wrong track due to previous experience. Something I need to watch for.