# Maximum depth of binary tree discussion

## First thoughts

This is another question that really just asks for a straightforward it does exactly what it says on the tin. The first thought was really how can you keep track of the depth whilst iterating through with recursion.

## MaxDepth
This really just uses a simple recursion method to traverse all of the tree and logs when it finds something that is deeper than the furthest depth. This ensures that we do not have one unusually long branching path being ignored and requires O(N) time complexity to hit every node.The hard part here is that when using recursion we need to store the information between function calls. In this version I thought that since we had a class structure in place to answer the question it makes sense to create a class variable.

## Thoughts
I may not have done the best thing here. Since this is a class it works but really if it where a class I would expect better functionality. For example maybe on creating the class we get the information via a constructor and just store it for later use and perhaps adding a value to the end of a branch checks if it changes the new depth. Maybe it would be better if it is just its own separate method and when we call the method it is stored in the outer method and the inner method. Or perhaps there is a version that does not require passing around variables other than the node themselves. There is a problem here with continuing development that I would probably address on a second look, but in terms of time complexity it does a reasonable job

