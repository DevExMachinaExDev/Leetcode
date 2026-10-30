# Binary search discussion.

## First thoughts

EASY! This is the simplest binary search problem you could get......... "proceeds to get it wrong". Haha my first thought was essentially the standard, I was aware of a binary search and exactly how it works and tried to implement it straight away. However in practice I made such simple off by one errors and logic errors it was a little humbling. Right after answering my first Hard question "Minimum window substring" as well haha. 

## search
The standard algorithm. We know the array is sorted therefore we grab the middle element, see if its correct higher or lower than the expected. If its the same return the element if its not decide whether to move the window left or right. Rinse and repeat until you run out of values or find the correct one.
The problems I had with the first attempt is i tried to store all the information about the next middle value in a single variable and some of the maths was a little off. So instead this approach uses a little more memory in the form of a left pointer and a right pointer to determine the window we are currently searching in and determines the middle that way and simple moves either the left or right pointer depending of if we are searching left or right. Its not necessary to do it this way, but becuase I have not done one in a while this seemed the simplest way to keep track of it. It runs in O(logn) due to it halving the values required every time and it has O(1) space complexity for the integers.

## Thoughts
I guess sometimes the nitty gritty can hold you back when you are out of practice. I haven't touch binary search in a long time and that probably affected answering this question. 