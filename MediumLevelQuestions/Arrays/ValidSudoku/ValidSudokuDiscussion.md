## Valid sudoku discussion  
First instincts
The honest truth is I did not really read this correctly the first time and I thought it was asking me to check whether the Sudoku could be completed, which is an entirely different question. Upon rereading it, my first instinct was to create a simple solution separating each of the three checks into their own loop.

## validSudokuMultiPass  
This was the first answer I came up with. I realised that rather than keeping a map containing each of the values and having to do all of those hash lookups and store all that data, it would be better to use a bitmask as we are dealing with a small number of predictable values. The bit logic of resetting the mask every cycle is as simple as setting an integer to zero rather than emptying a map every check. I created the actual check in its own method as it was becoming heavily repeated code for each check.

This technically asymptotically runs at the optimal speed for the problem as it runs at O(N²) time and O(1) space on a generalized NxN Sudoku board. It also has excellent memory complexity, requiring only a single reusable integer mask. This would probably be the solution you would use in a memory-tight scenario, but it suffers from having to do three entire passes of the matrix.

## validSudokuSinglePass  
This version trades a little extra memory for the sake of combining the three passes into a single pass. It uses three arrays of bitmasks as opposed to a single value and just runs through the array once making the necessary comparisons.

This technically has the same asymptotic time and memory complexity as above, but in practice it performs all checks in a single traversal of the board and stores 27 integer masks. This would likely be the maximum-speed solution for this problem.

## Additional thoughts  
I wonder if we really need to store all of those bitmasks for this. Since once we have done three rows we are done with three of the boxes, it feels like there may be another middle-of-the-road solution which would only store one integer for the horizontal line as it gets reset every time, three integers for the boxes as they get reset every three rows, and nine integers for the vertical checks as those only get resolved at the end of the run.

However, the additional checks required would add unnecessary complexity and reduce maintainability and readability.