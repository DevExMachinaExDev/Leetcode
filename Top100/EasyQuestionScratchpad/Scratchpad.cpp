#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>
#include <string>
#include <algorithm>
#include <stack>

// Contains code for quickly solving the easy level provlems on leetcode where it was not though necessary to do write ups.
// These questions were generally done for warmup or quick practice sessions.

/*
You are given a 2D integer array matrix of size n x n representing the adjacency matrix of an undirected graph with n vertices labeled from 0 to n - 1.

matrix[i][j] = 1 indicates that there is an edge between vertices i and j.
matrix[i][j] = 0 indicates that there is no edge between vertices i and j.
The degree of a vertex is the number of edges connected to it.

Return an integer array ans of size n where ans[i] represents the degree of vertex i.

 

Example 1:



Input: matrix = [[0,1,1],[1,0,1],[1,1,0]]

Output: [2,2,2]

Explanation:

Vertex 0 is connected to vertices 1 and 2, so its degree is 2.
Vertex 1 is connected to vertices 0 and 2, so its degree is 2.
Vertex 2 is connected to vertices 0 and 1, so its degree is 2.
Thus, the answer is [2, 2, 2].

Example 2:



Input: matrix = [[0,1,0],[1,0,0],[0,0,0]]

Output: [1,1,0]

Explanation:

Vertex 0 is connected to vertex 1, so its degree is 1.
Vertex 1 is connected to vertex 0, so its degree is 1.
Vertex 2 is not connected to any vertex, so its degree is 0.
Thus, the answer is [1, 1, 0].

Example 3:

Input: matrix = [[0]]

Output: [0]

Explanation:

There is only one vertex and it has no edges connected to it. Thus, the answer is [0].

 

Constraints:

1 <= n == matrix.length == matrix[i].length <= 100​​​​​​​
​​​​​​​matrix[i][i] == 0
matrix[i][j] is either 0 or 1
matrix[i][j] == matrix[j][i]
*/

std::vector<int> findDegrees(std::vector<std::vector<int>>& matrix) 
{
    int n = matrix.size();
    std::vector<int> toReturn(n, 0);

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            toReturn[i] += matrix[i][j]; 
        }
    }

    return toReturn;
}

/*
Given two integers, num and t. A number x is achievable if it can become equal to num after applying the following operation at most t times:

Increase or decrease x by 1, and simultaneously increase or decrease num by 1.
Return the maximum possible value of x.

 

Example 1:

Input: num = 4, t = 1

Output: 6

Explanation:

Apply the following operation once to make the maximum achievable number equal to num:

Decrease the maximum achievable number by 1, and increase num by 1.
Example 2:

Input: num = 3, t = 2

Output: 7

Explanation:

Apply the following operation twice to make the maximum achievable number equal to num:

Decrease the maximum achievable number by 1, and increase num by 1.
 

Constraints:

1 <= num, t <= 50
*/

int theMaximumAchievableX(int num, int t) 
{
    return num + t * 2;
}


/*
You are given a string s consisting of lowercase English letters.

Return an integer denoting the maximum number of substrings you can split s into such that each substring starts with a distinct character (i.e., no two substrings start with the same character).

 

Example 1:

Input: s = "abab"

Output: 2

Explanation:

Split "abab" into "a" and "bab".
Each substring starts with a distinct character i.e 'a' and 'b'. Thus, the answer is 2.
Example 2:

Input: s = "abcd"

Output: 4

Explanation:

Split "abcd" into "a", "b", "c", and "d".
Each substring starts with a distinct character. Thus, the answer is 4.
Example 3:

Input: s = "aaaa"

Output: 1

Explanation:

All characters in "aaaa" are 'a'.
Only one substring can start with 'a'. Thus, the answer is 1.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
*/

int maxDistinct(const std::string& s) 
{
    bool seen[26] = {false};
    int count = 0;

    for (char c : s) 
    {
        int idx = c - 'a';
        if (!seen[idx]) 
        {
            seen[idx] = true;
            count++;
        }
    }
    return count;
}



/*
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 

Example 1:


Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
Example 2:


Input: head = [7]
Output: [7]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes.
There are no pairs of adjacent nodes, so we return the initial linked list.
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
1 <= Node.val <= 1000
*/

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertGreatestCommonDivisors(ListNode* head) 
{
    ListNode* currentNode = head;

    while (currentNode && currentNode->next != nullptr) 
    {
        int greatestCommonDivisor = std::gcd(currentNode->val, currentNode->next->val);

        ListNode* newNode = new ListNode(greatestCommonDivisor);
        newNode->next = currentNode->next;
        currentNode->next = newNode;

        currentNode = newNode->next;
    }

    return head;
}

/*
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.

 

Example 1:

Input: s = "hello"

Output: 13

Explanation:

The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111. So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

Example 2:

Input: s = "zaz"

Output: 50

Explanation:

The ASCII values of the characters in s are: 'z' = 122, 'a' = 97. So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.

 

Constraints:

2 <= s.length <= 100
s consists only of lowercase English letters.
*/

int scoreOfString(std::string s) 
{
    int currentScore = 0;
    
    for(int i = 0; i < s.size() -1; ++i)
    {
        currentScore += std::abs(s[i] - s[i+1]);
    }
    return currentScore;
}

/*Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

 

Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
The elements in nums are distinct.
 

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?*/
std::vector<int> buildArray(std::vector<int>& nums) 
{
    int n = nums.size();
    std::vector<int> ans(n);

    for (int i = 0; i < n; i++) 
    {
        ans[i] = nums[nums[i]];
    }

    return ans;
}

/*You are given positive integers n and m.

Define two integers as follows:

num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
Return the integer num1 - num2.

 

Example 1:

Input: n = 10, m = 3
Output: 19
Explanation: In the given example:
- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
We return 37 - 18 = 19 as the answer.
Example 2:

Input: n = 5, m = 6
Output: 15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5], num1 is the sum of those integers = 15.
- Integers in the range [1, 5] that are divisible by 6 are [], num2 is the sum of those integers = 0.
We return 15 - 0 = 15 as the answer.
Example 3:

Input: n = 5, m = 1
Output: -15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 1 are [], num1 is the sum of those integers = 0.
- Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2 is the sum of those integers = 15.
We return 0 - 15 = -15 as the answer.
*/

int differenceOfSums(int n, int m) 
{
    int totalSum = n * (n + 1) / 2;

    int totalDividableByM = n / m;
    int divisibleSum = m * totalDividableByM * (totalDividableByM + 1) / 2;

    return totalSum - 2 * divisibleSum;
}

// or

int differenceOfSums(int n, int m) 
{
    return n * (n + 1) / 2 - m * (n / m) * ((n / m) + 1);
}

/*You are given an integer n.

Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

Return an integer denoting the mirror distance of n​​​​​​​.

abs(x) denotes the absolute value of x.

 

Example 1:

Input: n = 25

Output: 27

Explanation:

reverse(25) = 52.
Thus, the answer is abs(25 - 52) = 27.
Example 2:

Input: n = 10

Output: 9

Explanation:

reverse(10) = 01 which is 1.
Thus, the answer is abs(10 - 1) = 9.
Example 3:

Input: n = 7

Output: 0

Explanation:

reverse(7) = 7.
Thus, the answer is abs(7 - 7) = 0.
 

Constraints:

1 <= n <= 109
*/

int mirrorDistance(int n) 
{
    int rev = 0;
    int temp = n;

    while (temp > 0) {
        rev = rev * 10 + (temp % 10);
        temp /= 10;
    }

    return abs(n - rev);
}


std::vector<int> friendsInOrder(const std::vector<int>& finishingOrder, const std::vector<int>& friendIds)
{

    bool isFriend[101] = {};

    for (int id : friendIds)
    {
        isFriend[id] = true;
    }

    std::vector<int> friendsInFinishingOrder(friendIds.size());
    int nextInsertIndex = 0;

    for (int id : finishingOrder)
    {
        if (isFriend[id])
        {
            friendsInFinishingOrder[nextInsertIndex++] = id;
        }
    }

    return friendsInFinishingOrder;
}

/*
You are given an integer array nums of length n.

Construct a new array ans of length 2 * n such that the first n elements are the same as nums, and the next n elements are the elements of nums in reverse order.

Formally, for 0 <= i <= n - 1:

ans[i] = nums[i]
ans[i + n] = nums[n - i - 1]
Return an integer array ans.

 

Example 1:

Input: nums = [1,2,3]

Output: [1,2,3,3,2,1]

Explanation:

The first n elements of ans are the same as nums.

For the next n = 3 elements, each element is taken from nums in reverse order:

ans[3] = nums[2] = 3
ans[4] = nums[1] = 2
ans[5] = nums[0] = 1
Thus, ans = [1, 2, 3, 3, 2, 1].

Example 2:

Input: nums = [1]

Output: [1,1]

Explanation:

The array remains the same when reversed. Thus, ans = [1, 1].

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/

std::vector<int> concatWithReverse(const std::vector<int>& nums)
{
    const int numSize = nums.size();
    std::vector<int> result(numSize * 2);

    for (int i = 0; i < numSize; ++i)
        result[i] = nums[i];

    int writePos = numSize;
    for (int i = numSize - 1; i >= 0; --i)
        result[writePos++] = nums[i];

    return result;
}

/*
You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.
More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
Return nums after the rearrangement.

 

Example 1:

Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]
Explanation: 
The elements 9, 5, and 3 are less than the pivot so they are on the left side of the array.
The elements 12 and 14 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
Example 2:

Input: nums = [-3,4,3,2], pivot = 2
Output: [-3,2,4,3]
Explanation: 
The element -3 is less than the pivot so it is on the left side of the array.
The elements 4 and 3 are greater than the pivot so they are on the right side of the array.
The relative ordering of the elements less than and greater than pivot is also maintained. [-3] and [4, 3] are the respective orderings.
 

Constraints:

1 <= nums.length <= 105
-106 <= nums[i] <= 106
pivot equals to an element of nums.
*/


std::vector<int> pivotArray(std::vector<int>& nums, int pivot) 
{
    const int numSize = nums.size();
    int belowCount = 0;
    int equalCount = 0;
    int aboveCount = 0;

    for(int i = 0; i < numSize; ++i)
    {
        if (nums[i] < pivot)
            belowCount++;
        else if (nums[i] == pivot)
            equalCount++;
        else
            aboveCount++;
    }

    int currentSmallerPosition = 0;
    int currentLargerPosition = belowCount + equalCount;

    std::vector<int> result(numSize, pivot);

    for(int i = 0; i < numSize; ++i)
    {
        if(nums[i] < pivot)
        {
            result[currentSmallerPosition] = nums[i];
            currentSmallerPosition++;
        }
        else if(nums[i] > pivot)
        {
            result[currentLargerPosition] = nums[i];
            currentLargerPosition++;
        }
    }

    return result;
}


int minOperationsToMakeDivisibleByThree(const std::vector<int>& numbers) 
{
    int totalOperationsNeeded = 0;

    for (int value : numbers) 
    {
        totalOperationsNeeded += (value % 3 != 0);
    }

    return totalOperationsNeeded;
}

/*There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

 

Example 1:

Input: operations = ["--X","X++","X++"]
Output: 1
Explanation: The operations are performed as follows:
Initially, X = 0.
--X: X is decremented by 1, X =  0 - 1 = -1.
X++: X is incremented by 1, X = -1 + 1 =  0.
X++: X is incremented by 1, X =  0 + 1 =  1.
Example 2:

Input: operations = ["++X","++X","X++"]
Output: 3
Explanation: The operations are performed as follows:
Initially, X = 0.
++X: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
X++: X is incremented by 1, X = 2 + 1 = 3.
Example 3:

Input: operations = ["X++","++X","--X","X--"]
Output: 0
Explanation: The operations are performed as follows:
Initially, X = 0.
X++: X is incremented by 1, X = 0 + 1 = 1.
++X: X is incremented by 1, X = 1 + 1 = 2.
--X: X is decremented by 1, X = 2 - 1 = 1.
X--: X is decremented by 1, X = 1 - 1 = 0.
 

Constraints:

1 <= operations.length <= 100
operations[i] will be either "++X", "X++", "--X", or "X--".
*/

int finalValueAfterOperations(std::vector<std::string>& operations) 
{
    int numValue = 0;

    for(int i = 0; i < operations[0].size(); ++i)
    {
        if (operations[0][i] >= '0' &&  operations[0][i] <= '9')
        {
            numValue *= 10;
            numValue += operations[0][i] - '0';
        }
    }

    int operationsTotal = 0;
    for (int i = 0; i < operations.size(); ++i)
    {
        if(operations[i][0] == '+')
        {
            operationsTotal++;
            continue;
        }
        else if(operations[i][operations[i].size() - 1] == '+')
        {
            operationsTotal++;
            continue;
        }
        else if(operations[i][0] == '-')
        {
            operationsTotal--;
            continue;
        }
        else if(operations[i][operations[i].size() - 1] == '-')
        {
            operationsTotal--;
            continue;
        }
    }

    return numValue + operationsTotal;
}


/*
You are given an integer n.

The score of n is defined as the sum of d * freq(d) over all distinct digits d, where freq(d) denotes the number of times the digit d appears in n.

Return an integer denoting the score of n.

 

Example 1:

Input: n = 122

Output: 5

Explanation:

The digit 1 appears 1 time, contributing 1 * 1 = 1.
The digit 2 appears 2 times, contributing 2 * 2 = 4.
Thus, the score of n is 1 + 4 = 5.
Example 2:

Input: n = 101

Output: 2

Explanation:

The digit 0 appears 1 time, contributing 0 * 1 = 0.
The digit 1 appears 2 times, contributing 1 * 2 = 2.
Thus, the score of n is 2.
 

Constraints:

1 <= n <= 109
*/

int digitFrequencyScore(int n) 
{
    int frequencyTracker[10] {0};

    int numToCheck = n;

    while(numToCheck > 0)
    {
        int digit = numToCheck % 10;
        frequencyTracker[digit]++;
        numToCheck /= 10;
    }

    int digitFrequencyScore = 0;

    for (int i = 0; i < 10; ++i)
    {
        digitFrequencyScore += frequencyTracker[i] * i;
    }
    return digitFrequencyScore;
}

/*You are given an array of strings words, where each string represents a word containing lowercase English letters.

You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

The weight of a word is defined as the sum of the weights of its characters.

For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

Return a string formed by concatenating the mapped characters for all words in order.

 

Example 1:

Input: words = ["abcd","def","xyz"], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]

Output: "rij"

Explanation:

The weight of "abcd" is 5 + 3 + 12 + 14 = 34. The result modulo 26 is 34 % 26 = 8, which maps to 'r'.
The weight of "def" is 14 + 1 + 2 = 17. The result modulo 26 is 17 % 26 = 17, which maps to 'i'.
The weight of "xyz" is 7 + 7 + 2 = 16. The result modulo 26 is 16 % 26 = 16, which maps to 'j'.
Thus, the string formed by concatenating the mapped characters is "rij".

Example 2:

Input: words = ["a","b","c"], weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

Output: "yyy"

Explanation:

Each word has weight 1. The result modulo 26 is 1 % 26 = 1, which maps to 'y'.

Thus, the string formed by concatenating the mapped characters is "yyy".

Example 3:

Input: words = ["abcd"], weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]

Output: "g"

Explanation:​​​​​​​

The weight of "abcd" is 7 + 5 + 3 + 4 = 19. The result modulo 26 is 19 % 26 = 19, which maps to 'g'.

Thus, the string formed by concatenating the mapped characters is "g".

 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 10
weights.length == 26
1 <= weights[i] <= 100
words[i] consists of lowercase English letters.
*/

std::string mapWordWeights(std::vector<std::string>& words, std::vector<int>& weights)
{
    int n = words.size();
    std::string mappedWordWeights;
    mappedWordWeights.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        const std::string& w = words[i];
        int wordWeight = 0;

        int len = w.size();
        for (int j = 0; j < len; ++j)
        {
            int letterIndex = w[j] - 'a';
            wordWeight += weights[letterIndex];
        }

        int modValue = wordWeight % 26;
        char mappedChar = 'z' - modValue;

        mappedWordWeights.push_back(mappedChar);
    }

    return mappedWordWeights;
}

/*
You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.

 

Example 1:

Input: words = ["leet","code"], x = "e"
Output: [0,1]
Explanation: "e" occurs in both words: "leet", and "code". Hence, we return indices 0 and 1.
Example 2:

Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
Output: [0,2]
Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and 2.
Example 3:

Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
Output: []
Explanation: "z" does not occur in any of the words. Hence, we return an empty array.
 

Constraints:

1 <= words.length <= 50
1 <= words[i].length <= 50
x is a lowercase English letter.
words[i] consists only of lowercase English letters.
*/

std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) 
{
    std::vector<int> wordsContaining;
    wordsContaining.reserve(words.size());

    for (int idx = 0; idx < words.size(); ++idx)
    {
        const std::string& w = words[idx];
        int wSize = w.size();

        for (int i = 0; i < wSize; ++i)
        {
            if (w[i] == x)
            {
                wordsContaining.push_back(idx);
                break; // stop scanning this word once x is found
            }
        }
    }

    return wordsContaining;
}


/*Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"
 

Constraints:

The given address is a valid IPv4 address.
*/

std::string defangIPaddr(const std::string& address) 
{
    std::string out;
    out.reserve(address.size() + 6);

    for (char c : address) 
    {
        if (c == '.') 
        {
            out += "[.]";
        } else 
        {
            out += c;
        }
    }

    return out;
}

/*Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
int numIdenticalPairs(std::vector<int>& nums) 
{
    int count[101] = {0};
    int result = 0;

    for (int i : nums) 
    {
        result += count[i];
        count[i]++;
    }

    return result;
}

/*You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.

You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].

Return the array ans. Answers within 10-5 of the actual answer will be accepted.

Note that:

Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00
 

Example 1:

Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65 and converted in Fahrenheit is 97.70.
Example 2:

Input: celsius = 122.11
Output: [395.26000,251.79800]
Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26 and converted in Fahrenheit is 251.798.
 

Constraints:

0 <= celsius <= 1000
*/

std::vector<double> convertTemperature(double celsius) 
{
    std::vector<double> temps;
    temps.reserve(2);

    temps.push_back(celsius + 273.15);
    temps.push_back(celsius * 1.80 + 32.00);
    return temps;
}



/*
You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

Each answer[i] is calculated considering the initial state of the boxes.

 

Example 1:

Input: boxes = "110"
Output: [1,1,3]
Explanation: The answer for each box is as follows:
1) First box: you will have to move one ball from the second box to the first box in one operation.
2) Second box: you will have to move one ball from the first box to the second box in one operation.
3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.
Example 2:

Input: boxes = "001011"
Output: [11,8,5,4,3,4]
 
*/

std::vector<int> minOperations(const std::string& boxes) 
{
    int n = boxes.size();
    std::vector<int> movesNeeded;
    movesNeeded.reserve(n);

    int ballsSeen = 0;
    int costToCurrent = 0;

    for (int i = 0; i < n; i++) 
    {
        movesNeeded.push_back(costToCurrent);
        if (boxes[i] == '1') ballsSeen++;
        costToCurrent += ballsSeen;
    }

    ballsSeen = 0;
    costToCurrent = 0;

    for (int i = n - 1; i >= 0; i--) 
    {
        movesNeeded[i] += costToCurrent;
        if (boxes[i] == '1') ballsSeen++;
        costToCurrent += ballsSeen;
    }

    return movesNeeded;
}

/*
You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

Example 1:

Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
Example 2:

Input: jewels = "z", stones = "ZZ"
Output: 0
 

Constraints:

1 <= jewels.length, stones.length <= 50
jewels and stones consist of only English letters.
All the characters of jewels are unique.
*/

int numJewelsInStones(const std::string& jewels, const std::string& stones)
{
    bool isJewel[128] = { false };

    for (char c : jewels)
        isJewel[(unsigned char)c] = true;

    int count = 0;

    for (char c : stones)
        count += isJewel[(unsigned char)c];

    return count;
}

int numJewelsInStones(const std::string& jewels, const std::string& stones)
{
    uint64_t mask = 0;

    for (char c : jewels)
        mask |= 1ULL << ((unsigned char)c - 'A');

    int count = 0;

    for (char c : stones)
        count += (mask >> ((unsigned char)c - 'A')) & 1ULL;

    return count;
}

/*In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1. Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in an additional time, making the list longer than usual.

As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing the two numbers (in any order), so peace can return to Digitville.

 

Example 1:

Input: nums = [0,1,1,0]

Output: [0,1]

Explanation:

The numbers 0 and 1 each appear twice in the array.

Example 2:

Input: nums = [0,3,2,1,3,2]

Output: [2,3]

Explanation:

The numbers 2 and 3 each appear twice in the array.

Example 3:

Input: nums = [7,1,5,4,3,4,6,0,9,5,8,2]

Output: [4,5]

Explanation:

The numbers 4 and 5 each appear twice in the array.

 

Constraints:

2 <= n <= 100
nums.length == n + 2
0 <= nums[i] < n
The input is generated such that nums contains exactly two repeated elements.*/


std::vector<int> getSneakyNumbers(std::vector<int>& nums) 
{
    int found[10] = {0};

    std::vector<int> toReturn;
    toReturn.reserve(2);

    for (int i = 0; i < nums.size(); ++i)
    {
        if (found[nums[i]])
        {
            toReturn.push_back(nums[i]);
        }
        found[nums[i]] = true;
    }

    return toReturn;
}

std::vector<int> getSneakyNumbers(std::vector<int>& nums)
{
    uint64_t mask0 = 0;
    uint64_t mask1 = 0;

    std::vector<int> out;
    out.reserve(2);

    for (int x : nums)
    {
        if (x < 64)
        {
            uint64_t bit = 1ULL << x;
            if (mask0 & bit)
                out.push_back(x);
            mask0 |= bit;
        }
        else
        {
            uint64_t bit = 1ULL << (x - 64);
            if (mask1 & bit)
                out.push_back(x);
            mask1 |= bit;
        }
    }

    return out;
}

std::vector<int> countBits(int n) 
{
    std::vector<int> ans;
    ans.reserve(n+1);

    ans.push_back(0);

    for (int i = 1; i <= n; i++)
        ans.push_back( ans[i >> 1] + (i & 1));

    return ans;
}

/*
You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:

Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.
Return the resulting array after performing these operations.

 

Example 1:

Input: nums = [4,3,2,1]

Output: [0,0,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
After sorting nums in non-descending order, nums = [0, 0, 1, 1].
Example 2:

Input: nums = [1,5,1,4,2]

Output: [0,0,1,1,1]

Explanation:

Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 1000
*/

std::vector<int> transformArray(std::vector<int>& nums)
{
    int evens = 0;

    for (int i = 0; i < nums.size(); ++i)
        evens += !(nums[i] & 1); 

    for (int i = 0; i < evens; ++i)
        nums[i] = 0;

    for (int i = evens; i < nums.size(); ++i)
        nums[i] = 1;

    return nums;
}

/*Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

Given a balanced string s, split it into some number of substrings such that:

Each substring is balanced.
Return the maximum number of balanced strings you can obtain.

 

Example 1:

Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
Example 2:

Input: s = "RLRRRLLRLL"
Output: 2
Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
Example 3:

Input: s = "LLLLRRRR"
Output: 1
Explanation: s can be split into "LLLLRRRR".
 

Constraints:

2 <= s.length <= 1000
s[i] is either 'L' or 'R'.
s is a balanced string.
*/

int balancedStringSplit(const std::string& s)
{
    int count = 0;
    int bal = 0;

    for (char c : s)
    {
        bal += (c == 'R') ? 1 : -1;
        count += (bal == 0);
    }

    return count;
}

/*Given a 0-indexed integer array nums of length n and an integer target, return the number of pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
 

Example 1:

Input: nums = [-1,1,2,3,1], target = 2
Output: 3
Explanation: There are 3 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = 0 < target
- (0, 2) since 0 < 2 and nums[0] + nums[2] = 1 < target 
- (0, 4) since 0 < 4 and nums[0] + nums[4] = 0 < target
Note that (0, 3) is not counted since nums[0] + nums[3] is not strictly less than the target.
Example 2:

Input: nums = [-6,2,5,-2,-7,-1,3], target = -2
Output: 10
Explanation: There are 10 pairs of indices that satisfy the conditions in the statement:
- (0, 1) since 0 < 1 and nums[0] + nums[1] = -4 < target
- (0, 3) since 0 < 3 and nums[0] + nums[3] = -8 < target
- (0, 4) since 0 < 4 and nums[0] + nums[4] = -13 < target
- (0, 5) since 0 < 5 and nums[0] + nums[5] = -7 < target
- (0, 6) since 0 < 6 and nums[0] + nums[6] = -3 < target
- (1, 4) since 1 < 4 and nums[1] + nums[4] = -5 < target
- (3, 4) since 3 < 4 and nums[3] + nums[4] = -9 < target
- (3, 5) since 3 < 5 and nums[3] + nums[5] = -3 < target
- (4, 5) since 4 < 5 and nums[4] + nums[5] = -8 < target
- (4, 6) since 4 < 6 and nums[4] + nums[6] = -4 < target
 

Constraints:

1 <= nums.length == n <= 50
-50 <= nums[i], target <= 50*/

int countPairs(std::vector<int>& nums, int target) 
{
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    while (left < right) 
    {
        if (nums[left] + nums[right] < target) 
        {
            count += (right - left);
            left++;
        } else
        {
            right--;
        }
    }

    return count;   
}
/*
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
 

Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int rangeSumBST(TreeNode* root, int low, int high) 
{
    std::stack<TreeNode*> stack;
    int sum = 0;
    stack.push(root);
    while (!stack.empty()) 
    {
        TreeNode* node = stack.top();
        stack.pop();
        if (node) 
        {
            if (node->val >= low && node->val <= high) 
            {
                sum += node->val;
            }
            if (node->val > low) 
            {
                stack.push(node->left);
            }
            if (node->val < high) 
            {
                stack.push(node->right);
            }
        }
    }
    return sum;
}
