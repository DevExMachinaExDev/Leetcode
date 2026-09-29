# Container with the most water solution explanations.

## maxAreaTwoPointer

This method takes advantage of a two pointer system with one pointer coming from the left of an array and one coming from the right grabbing the best solutions possible along the way by calculating the area with each move. This way it will always have the largest found container. It complete in O(N) time which is necessary as you need to touch each array element once. It is also O(1) memory complexity.