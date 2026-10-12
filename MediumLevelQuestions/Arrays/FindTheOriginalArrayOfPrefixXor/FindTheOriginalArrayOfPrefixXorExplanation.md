# Find the original array of prefix XOR Explanation 

## findArrayFastest

This solution was the most efficient way I could think to solve this problem. Since we have to populate an array we must touch each array element once for a simple O(n) time complexity. We create the array and reserve memory (for O(n) space complexity necessary to return) to prevent having to resize the array at runtime and prevent having to run through the array and change all values within it which happens when not using reserve. We then simply iterate over the array xOring each value with its previous. The trick comes from the fact that when you XOR something with the same value twice, you get the original value back, because XOR only flips the bits that differ between the two values. So essentially you just repeat the initial process described in the question.

## findArraySTL

This was just done as a means to re-familiarise with the STL as i feel that the fastest solution is perfectly readable. This version turns the loop into a one-liner using the transform function which essentially iterates through an array applying the inputted function to each member, we pass in our lambda function here which does the XOR operation and we are done. I would not typically do something like this as I feel it adds an unnecessary library and unnecessary overhead.


### Additional comments.

Its hard to see how this could be further improved as it is such a simplistic problem and it almost requires a standard iterative approach to work, but it provided some good practice into this simple looping technique and also refreshed the important insight into how XOR logic reverses itself.