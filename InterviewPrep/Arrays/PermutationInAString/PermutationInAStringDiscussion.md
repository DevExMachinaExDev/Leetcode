# Permutation in a string discussion.

## First instincts

Honestly i did this question directly after "Find all anagrams in a string" and I was sick the day i did this and I had to read it a few times to check it wasn't the same question worded differently haha. I ultimately found that it pretty much is a simpler version of find all anagrams in a string except for the key difference that it can exit early if it finds the permutation and it only wants the bool. It might have been better to have gotten this question first as the logic is ever so slightly simpler.

## checkInclusionSlidingWindowTrackingArrays
This code looks..... ahem..... familiar. Yes i repurposed the answer from "find all anagrams in a string" and edited it very slightly with the above touches so it might be worth just reading that answer to see how it works. The only key difference being that this one exits early if it has found a string and returns a bool with true if it has otherwise it scans the entire thing and returns false.

## Thoughts
If nothing else this is really a lesson that you should keep your code snippets and have an idea of problems you have solved in the past. I was a little uneager to write what i had just written again today as I was a little sick and it was a relatively long winded piece of code, but the practice of taking one piece of code and understanding what needed editing and how it can be repurposed as well as the pattern recognition that it is a very similar problem is a skill that needs sharpening. It might not have been the best in terms of pure interview practice but there is definitely something valuable to be taken from that and I should be easier on myself on days like this.