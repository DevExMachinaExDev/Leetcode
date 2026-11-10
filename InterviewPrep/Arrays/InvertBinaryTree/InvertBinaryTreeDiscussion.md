# Invert Binary tree discussion.

## First instincts
With this type of question it is so clear what structure you need to use that it does not really bear a lot of discussion, however there are a few questions that we need to ask ourselves. First off with a binary tree there is always Breadth first vs depth first searching and whether or not to use the call stack vs using an additional data structure such as a list, queue or stack to store information.


## Invert binary tree.
I opted to use the call stack for this question because for the most part it simplifies the implementation. By its very nature this question is simplified by going depth first because we can traverse all the way the to bottom and swap the children at the base of the tree first and then move up and swap the next layer. So essentially we go depth first by using recursion with the method calling itself and repeatedly and going left first until it reaches a dead end upon which it does nothing exiting out into the one above which checks the right path and when it comes back out of both paths it just swaps its left and right. The algorithm has a time complexity of O(N) having to visit every branch at least once . Its space complexity is O(H) where the h is the height of the tree because it stores only the values above the node.

## Thoughts
In some ways I am unsure of the recursive structure here. It creates a very simple set of code but it has to be said that this structure is not super robust when there is a large data set the stack could easily overflow, but the benefits od the simpler code are plain to see. An alternative version might involve simply storing them all in a list in the correct order and then swapping using mathematics to find the corect swaps, but this was unnecessarily complex.