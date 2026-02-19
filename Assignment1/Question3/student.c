#include "Student.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = malloc(digitsSize * sizeof(int)); // allocate new array
    for (int i = 0; i <digitsSize; i++) ans[i] = digits[i]; // copy nums over to new array

    for (int i = 0; i < digitsSize; i++) { // incrementing loop
        if (++digits[digitsSize-1 - i] > 9) {
            ans[digitsSize-1 - i] = 0;
        }
        else {
            ans[digitsSize-1 - i] = digits[digitsSize-1 - i];
            break;
        }
    }
    if ((ans[0] == 0)) { // checks overflow
        if (ans[digitsSize-1] == 1) { // for all zeros case
            *returnSize = digitsSize;
            return ans;
        }
        ans = calloc(digitsSize+1, sizeof(*digits)); // create new array one digit longer, all set to zero
        ans[0] = 1; // set first index to one
        *returnSize = digitsSize + 1;
    }
    else {
        *returnSize = digitsSize;
    }
    return ans;
}

