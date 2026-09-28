# Explanation of coding 

Below is an explanation of the choices made for the multiple versions of the Two sum problem solution.

## Two sum brute force

This is the simplest way to solve the problem and is what may be used under time constraints. It visits every item in the array and compares it against every other item in the array that is ahead of what has already come. This is not the optimal solution for Time complexity sitting at O(N^2) and ideally we would want to only visity each value once for O(N) complexity, but it provides only O(1) memory complexity storing only the array to be returned meaning in situations where memory tight this may be viable.


## Two sum Hash map

This version uses a hash map to store what the addition value needed will be paired with its position in the array as it goes requiring only a single pass and being O(N) complexity. Since this task requires looking through each array element this is the fastest this can be performed at the cost of O(N) memory complexity. There are additional measures to prevent slowdowns added. For example the memory required for the hash map is pre-allocated. This means that it will always use additional memory equivalent to the size of the array but has the benefit of never having to re-allocate the entire hash map. Additionally the use of an iterator creates a pointer which can then be looked up instantly when assigning the value preventing dual look ups.
