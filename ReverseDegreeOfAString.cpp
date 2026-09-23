/*Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

For each character, multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) with its position in the string (1-indexed).
Sum these products for all characters in the string.
Return the reverse degree of s.*/

int reverseDegree(char* s) 
{
    int total = 0;

    int currentIndex = 1;
    for (char* c = s; *c != '\0'; ++c)
    {
        total += ('z' - *c + 1) * currentIndex;
        currentIndex++; 
    } 

    return total;
}

// Lesson here is that strlen function iterates over the entire string to get the lenghth of it wheras if we just search for the string termination character we only have to do it once. 

// Be careful of strlen use.