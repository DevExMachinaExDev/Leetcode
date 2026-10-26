# Move Zeroes Discussion

## First instincts

I feel like the name of the question kind of nudges you in the wrong direction with this one. The restriction saying not to create an extra array also made me think that using outside data structures in any form other than a few ints was probably a no-no, as I would definitely have thought of exploiting that wording to just use a similar data structure :D.

I played nice though and realised the spirit of the question wants you to move things around in the array. My first sort of incomplete thought was that I wanted to do a run of the array to find the number of zeroes, then go through from that point onwards converting values to zeroes and pushing them back, but that does not really work because in practice you still have to either shift everything back repeatedly or store the values that would be overwritten.

## moveZeroesTwoPointer

It took me a while, but I started thinking about storing where I wanted the next digit to be. At first I thought I should do it with the zeroes, but that fell apart because they are at the end and approaching the problem from any direction while tracking them makes little sense.

Then I figured that I could just start to populate the array as I go, knowing that all of the remaining values at the end will eventually be zeroes. This version does exactly that by keeping track of where we put the last non-zero value and placing the next non-zero value after it.

It technically has to run over a fully zero array twice, but still runs in O(N) time complexity with a space complexity of O(1).

## Thoughts

Of course, the version with an extra data structure is the one you would initially think of here, and if the final values were anything other than a single known value we would have to consider storing another array or some kind of structure. However, it was a good lesson in how a question can influence your thinking through its wording, as really you are not moving the zeroes but moving the other integers and then filling the remaining positions with zeroes.