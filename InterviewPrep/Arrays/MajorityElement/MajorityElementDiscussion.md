# Majority element discussion

## First instincts  

This one stumped me for the optimal solution without having to look it up in all honesty. It had been a long time since i had used a voting algorithm and perhaps due to the other questions answered on this day I could only think to use a hash map solution for it. After trying for a while I found the solution was something i had come across a long time ago but hadn't used for a long time, which goes to show why you should refresh your knowledge periodically, but the explanation remains valid all the same.

## majorityElementVoting

This is the optimal algorithm with O(n) time complexity being necessary to check enough elements. It essentially works off the quirk that if that value appears most often it would always win in a voting war against the other numbers because once encountered others would have a hard time outvoting it and even if they did it would win the vote again by the end. A really clever algorithm which forgoes the need to compare them at all and just really "sort of" counts the instances of the most frequently occurring.

## majorityElementHashMap

Included because it was honestly the best solution i came up with alone without looking things up, but it has no benefits over the best solution. Has O(n) time complexity which in itself is probably slower than the voting solution due to the hash lookups. It simply stores each found value and the highest number of them and when a number it finds is greater than the highest that becomes the new element that we return. It really falls down in comparison to the voting algorithm with its O(n) space complexity.


## best guess algorithm
Just a theoretical and not actually implemented as it would not always be correct but for very large values where you are concerned with speed you could potentially take random samples and pick the one that occurs the most or even random windows and pick the one that occurs the most. Of course this system could be fooled but would work most of the time and in unimportant scenarios such as video games where performance is more crucial this could be an option. This would need to be checked in practice however due to it being quite hard to beat a sequential algorithm for speed and it would be a tradeoff in reliability. You could even use a modified voting algorithm itself on the random values as your means of finding it.