# Product of array except self discussion.

## First instinct
I guess maybe it was the way the question is worded particularly the title but my first instinct with this one was to try and do a single run through to get the total product and then divide it by the current element when populating the array (which in the real world without constraints is probably the best action here). Unfortunately in order to do that you need to divide which the problem forbids, so my first attempt was to implement my own division system.

## productExceptSelfHomeMadeDivide  

The simplest way of finding a product without itself is surely to find the product and remove the self. This is what was attempted, but implementing a divide is not so easy in good time complexity. I considered that an integer divide is just how many times something can be taken from something else and came up with a looping solution that tracks this. However that does mean we don't hit the O(N) target as i guess this is O(n * k) where k is the number of divides necessary. It does a decent job of being only O(N) memory though. Ultimately I think the question is framed to keep you away from attempting this solution.

## productExceptSelfTwoRuns

Cards on the table. This took me way too long to figure out. The solution essentially works by tracking the current product of everything on the left of the value in the first sweep and then multiplying it by the product of everything on the right on the second reverse sweep. My first attempt of this was to do something somewhat similar in that i did a first reverse sweep to get the total and then tried to track the left total and add it to the right total every time getting some very incorrect outputs as you can probably imagine. However i finally looked at a couple of hints and was able to get it working without too much direct help. The final solution here rests at O(n) time complexity although it requires two sweeps and O(N) space complexity.

## Thoughts

I can't really think of a better way that this can be done as its mostly just about simply understanding the mathematics that you can multiply two partial products to get a total product, but it is a good delve into how you can use mathematics to prevent having to do extra work in algorithms and it is always worth checking if there is a more mathematically sound way of doing something. I guess you also have the message that sometimes its just about not having too many assumptions based on the problem itself as there may be a slightly more abstract way of thinking about it.