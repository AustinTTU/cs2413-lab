/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
// static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);
static int remove_item(int* heap, int size);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) { // I used a max-heap based approach:
    /* Write your code here */
    if (numsSize == 0) return 0; // base case, if array is empty return

    // Turn array into heap:
    for (int i = (numsSize/2) - 1; i >= 0; i--) { // start at (numSize/2) - 1 because that is the first non-leaf node
        heapifyDown(nums, numsSize, i); // use heapify to fix array to match heap properties
    }
    for (int i = 1; i < k; i++) { // delete k times in max heap to find the kth largest element
        remove_item(nums, numsSize);
        numsSize--;
    }
    return nums[0]; // return kth largest element
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    /* Write your code here if you use this helper */
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
// static void heapifyUp(int* heap, int index) {
//     /* Write your code here if you use this helper */
// }

/* Additional Helpers I made: */
int left_child(int i) {
    return 2 * i + 1;
}

int right_child(int i) {
    return 2 * i + 2;
}

int remove_item(int* heap, int size) { // removes and returns root (which is max value)
    if (size == 0) return -1;

    int max_value = heap[0]; // store root
    heap[0] = heap[size-1]; // set new root as last element, preserves correct shape
    size--; // decrease size

    if (!(size == 0)) { // check if empty
        heapifyDown(heap, size, 0); // heapify, starting at the root, to preserve heap properties
    }
    return max_value; // return deleted root
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    /* Write your code here if you use this helper */
    while(1) {
        int left = left_child(index);
        int right = right_child(index);
        int largest = index;

        if ((left < size) && (heap[left] > heap[largest])) largest = left;
        if ((right < size) &&(heap[right] > heap[largest])) largest = right;
        if (largest == index) break;

        swap(&heap[index], &heap[largest]);
        index = largest;
    }
}