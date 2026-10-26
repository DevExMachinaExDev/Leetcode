# Group anagrams discussion

## First instincts
So my first instinct with this is that it not a matter of a single pass through as you would need to check it against all the other values that have already been found.

I then thought of which would be the easiest way of understanding this problem and the version i could best think of was to use an algorithm to convery all of the values into the same thing so they can be directly compared using a map and thats when i came up with the first solution.

After this solution I thought of a version using a bitmask to store all of the values found but realised this falls prey to the problem that an anagram can contain multiple of the same character so it cannot so easily be translated into that.

## groupAnagramsSortedString map
This anagram takes each individual string and sorts it so that it can be easily added to a map and then reads all the values in the map into their individual vectors for O(k log k) time from the sorting algorithm itself and O(n) space complexity. This was the most readable form as its easy to understand that if you conver the anagram into sorted they will be the same as other anagrams. 



## Post answer research  
After some research I found that there is a version of this problem where you can convert the frequency map into a hash map using a custom built hashing function, but since it was not my own design I did not add it in here. Essentially it does the same first step of finding the frequencies using the hash map, but instead of sorting each word it builds a frequency signature for the word and uses that as the key. This avoids the O(k log k) sorting step and reduces the overall complexity from O(n * k log k) to O(n * k), where n is the number of strings and k is the average string length. While this is theoretically more efficient, the additional complexity of implementing and maintaining a custom hash function in C++ makes the sorted-string solution the cleaner and more readable approach for most interview scenarios and given the small problem constraints it did not seem like this implementation was worthwhile.

## Other ideas

I wonder if there can be solutions that can scan the array for strings that contain only unique letters and use the bitmasking approach and maybe some form of advanced bitmasking when it finds multiple of the same value so perhaps if it finds that there are only at max 3 differences it then takes those ones and uses and advanced bitmap that is 3 times the length of the original, but this could of course get very messy when you have very long strings of all the same letter. Or even more advanced it would first scan the string and decide which algorithm is optimal (this could double as doing the bitmask on this pass as then it will have automatically done it id its relevant). This however is experimental and like shooting a fly with a bazooka but interesting as a thought experiment.

