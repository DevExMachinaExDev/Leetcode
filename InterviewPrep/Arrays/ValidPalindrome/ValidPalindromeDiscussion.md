# Valid palindrome discussion.

## First instincts
Honestly after hacing done "longest consecutive" and "product of array except self" this one was a bit of a relief. Its pretty standard knowledge that palindromes are best dealt with with a two pointer approach as that is sort of the nature of the beast. The only slight hiccup is dealing with characters that and not alphabetical.

## Valid palindrome
So rather than use a load of extra memory and create a new string that we can then remove elements from and create a load of work it made sense to me to just skip elements that are irrelevant. For the left pointer that is simply skipping to the next loop and for the right we have an inner loop which appears to be O(N^2) but since in reality the loop checks if the pointers have passed or are equal it is just another iteration of the outside loop. If it finds something that is not correct it returns false and if it does the entire string it returns true so it has a nice early exit in certain circumstances as well.

## Additional thoughts
Fairly standard question. There are other variations where you start from the middle and work outwards but fundamentally this just adds complication.