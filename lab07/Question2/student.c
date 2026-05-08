/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/
void merge(int arr[], int left, int mid, int right);
void mergeSortRecursive(int arr[], int left, int right);

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    (void)arr;
    (void)size;
    int left = 0;
    int right = size-1;
    mergeSortRecursive(arr, left, right);
}

void mergeSortRecursive(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) /2;

        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else temp[k++] = arr[j++];
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int t = 0; t < k; t++) {
        arr[left + t] = temp[t];
    }
}
