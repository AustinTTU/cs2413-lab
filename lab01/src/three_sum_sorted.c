#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    
    // implement your code here

    if (n < 3) return 0; // invalid input case

    for (int i = 0; i < n; i++) {
        int j = i + 1; // left pointer
        int k = n - 1; // right pointer
        /* Essentially do twosum problemw with negative of first index
        to sum to total of zero */
        while ((j < k) && (k > j)) {
            if (nums[k] + nums[j] < (nums[i] * -1) ) {
                j++;
            }
            else if (nums[k] + nums[j] > (nums[i] * -1)) {
                k--;
            }
            else { // sum equal to zero, return values
                *out_i = i;
                *out_j = j;
                *out_k = k;
                return 1;
            }
        }
    }
    return 0;
}
