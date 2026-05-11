/*
Question 5: Selection Sort

Description:
Implement selection sort for an integer array.

Selection sort repeatedly finds the smallest element from the unsorted
portion of the array and swaps it with the first element of the unsorted
portion.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
- Do not use any built-in sorting function.
*/

int smallest(int arr[], int k, int size);
void swap(int* a, int* b);

void selectionSort(int arr[], int size) {
    // TODO: implement selection sort
    (void)arr;
    (void)size;
    for (int i = 0; i < size; i++) {
        int pos = smallest(arr, i, size);
        swap(&arr[i], &arr[pos]);
    }
}

int smallest(int arr[], int k, int size) {
    int small = arr[k];
    int pos = k;
    for (int i = k+1; i < size; i++) {
        if (small > arr[i]) {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

