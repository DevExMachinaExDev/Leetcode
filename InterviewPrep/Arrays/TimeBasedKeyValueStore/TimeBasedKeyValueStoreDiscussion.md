# Time based key value store discussion.

## First instincts.

A little bit of a cheat with this one as I looked over my questions and knew that I was still in the binary search category. I feel sometimes that these questions that ask you to define a class are always worded so very badly and hard to understand what they are asking for, but are offset by the fact that these are the types of data structures you will likely actually be working with in industry as we rarely just have clean cut situations most of the time. My first thought for this was that really its just a fancy wrapper around a map to make it so you can find the highest value faster and by inputting the information in order of time we have a system where the values can be placed in order, and if they are in order we can binary search them.

## TimeMap

The constructor and the Setter are not the core of the problem here so they are honestly just kept as basic as possible with a default constructor and a set method that allows adding elements. The getter is the hard part as we need to retrieve the right information. This is where a simple binary search is done checking if the value is the correct one and if it is set it and search for a better one and if not move until you find one. It works in O(logn) time.

## Thoughts

A little rushed from me today as I am playing catchup due to life circumstances but all in all the biggest hurdle of this problem is just the wording. It wants something very simple but it does not really tell you what it actually wants I had to use the comments just to understand it. There is definitely a lesson there about clarifying the requirements and communication though.