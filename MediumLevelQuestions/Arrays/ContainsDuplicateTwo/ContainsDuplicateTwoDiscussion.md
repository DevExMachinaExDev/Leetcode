# Contains duplicate 2 discussion.

## First instincts

When i first saw this my immediate thought was to use a loop to iterate through the list once and use a hash map to store all of the values that had already been visited with their index and then to travel through and when you see the value again check if it has already been found within the map and if that index is within K distance. This would have worked pretty well but it seemed like it was a waste of memory when we really don't need to store N values in the map.

## containsNearbyDuplicateSlidingWindow

Once i had realised this could be solved in O(n) with my above approach which theoretically would be the minimum because we need to check every value. I moved on to trying to reduce that memory. I realised that at any one time the hash map only needs to contain the last K values. This means that a sliding window approach can be used by removing unnecessary values in the map as we go giving us an O(min(k, n)) space complexity which under most circumstances other than the worst case is optimal. Using this approach I did a first pass just to do the check without deleting the value and did the second pass with a pointer. This was done to separate the concerns slightly but also for the slight performance gain from reducing the branching where unnecessary in the second loop. Overall this is the solution i would use if we were concerned about speed with a little concern about memory although arguably the constant erasing could reduce speed (it should still be O(N)) a little where memory is not a concern we could have used my original idea.

## containsNearbyDuplicateBruteForce

The naive approach with O(N^2) complexity has some benefits despite its simplistic approach. It uses a brute force technique of trying all elements within k range of this element (a minor optimisation rather than checking all the elements in the array needlessly). This has the benefit that other than the variables used for the loop itself this requires no stored memory. This would definitely be more useful in a situation where memory is the greatest concern and we can afford to trade off time complexity.