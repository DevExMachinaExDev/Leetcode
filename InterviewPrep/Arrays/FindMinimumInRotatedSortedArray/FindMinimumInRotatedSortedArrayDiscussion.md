# Find minimum in a rotated sorted array discussion.

## First thoughts

I was fresh off search a rotated sorted array when I did this question and honestly I think my first approach and my first attempt at it kind of spoiled this question a bit as I had already somewhat figured out to do this.

## findMin

So finding the minimum is not really finding the minimum in this question... well it is... but its not the best way to approach it. Really what you are looking for is where the split is and thats a little easier to find with a binary search. With a binary search we can check for any order anomalies by simply checking does the list on the left have any values greater than on the right. If it does then we select the side that is out of order and zoom in on it by halving the array. When we find that we have a completely sorted array where the left value is less than the right value, the left values must be the smallest in the array because if that is the fully sorted section and the lowest then it must be there. It runs at O(logn) as its really just a single modified binary search with O(1) space for the few stored variables.

## Thoughts

The hardest part of these questions honestly seems to be the off by one errors that are taking the most time it is very easy to accidentally have a window be too large or small or have infinite loops (which i did a couple of times whilst writing this).
I think this question is a good example of how previous knowledge can certainly help you to solve future problems, and its proof of something I was once told in dev work that "most of the work we do is a knowledge check, not an intelligence check" and that really played out here. I knew that I could find the min here because i knew how to find the min and to check the sides for sorting irregularities.