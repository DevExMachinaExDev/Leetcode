# Two sum discussion  

## First instincts

My first instinct with a problem like this is I probably only need a single pass whilst using some memory to store important information so I think it would be O(n) time if I can store things. I immediately note that the obvious brute force solution is also just the classic "compare everything with everything" until you get the answer.

## twoSumSpeed

The fastest solution is O(n) time complexity but also potentially O(n) space complexity. We can use a map to store values we have already visited so you could either store the current value and each time do the sum to see if it hits it or you can store the value you are looking for and then if you find it it means you have the sum. The truth is they have very little meaningful performance differences as the same number of calculations must take place either way. This algorithm is a relatively standard hash lookup.

## twoSumMemory

Brute force here requires no additionaly memory other than the loops and the variable vector to return so it manages to get to O(1) memory complexity. However since we must check everything over everything it is an O(N^2) time complexity meaning it would quickly become unmanagable with large arrays. This is the solution you would use if you had memory restrictions and smaller arrays.

## The bit solution 

This was not implemented due to its general impracticality, but technically this could be made faster by using a bitmap and mapping every possible integer value to a bit. Checking whether a value had already been seen would then become a simple bit test rather than a hash lookup. However, given the large value range in the problem constraints, this would require a very large fixed-size memory allocation. Whilst this is technically O(1) space complexity because it does not grow with the input size, the constant memory requirement would be so large that it is generally impractical compared to the hash map solution. Though arguably in worst case scenarios the hash map solution would require far more memory as it would require space for all the integers and their positions in most instances it would be faster. An ideal solution may be that the algorithm checks the size of the input array and decides which solution to use from there although this might be beyond the scope of this question.