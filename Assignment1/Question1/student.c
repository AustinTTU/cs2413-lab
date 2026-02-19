#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (nums2Size != n){
        return;
    }
    for (int i = n-1; i >= 0; i--) { // merge the arrays into nums1
        nums1[i+m] = nums2[i];
    }
    for (int i = 0; i < nums1Size; i++) { // sort nums1 via bubble sort
        for (int j = 0; j < nums1Size-i-1; j++) {
            if (nums1[j] > nums1[j+1]) {
                int temp = nums1[j+1];
                nums1[j+1] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}
