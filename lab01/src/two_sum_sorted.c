#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.

    int i = 0; // left pointer
    int j = n - 1; // right pointer
    while ((i < n) && (j > 0)) {
        if (nums[i] + nums[j] < target) { // sum too small, obtain larger i
            i++;
        }
        else if (nums[i] + nums[j] > target) { // sum too big, obtain smaller j
            j--;
        }
        else { // must be equal, return values
            *out_i = i;
            *out_j = j;
            return 1;
        }
    }
    return 0;
}
// think about the time complexity and space complexity of your solution

