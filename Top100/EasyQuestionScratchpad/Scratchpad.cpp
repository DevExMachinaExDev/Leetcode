#include <vector>
#include <string>
#include <unordered_set>
#include <numeric>

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


int minOperationsToMakeDivisibleByThree(const std::vector<int>& numbers) {
    int totalOperationsNeeded = 0;

    for (int value : numbers) {
        totalOperationsNeeded += (value % 3 != 0);
    }

    return totalOperationsNeeded;
}

