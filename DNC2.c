#include <stdio.h>

void find_min_max(int arr[], int low, int high, int *min_val, int *max_val) {
    // If the array contains only one element, return that element as both minimum and maximum
    if (low == high) {
        *min_val = arr[low];
        *max_val = arr[low];
        return;
    }

    // If the array contains two elements, return the minimum and maximum of the two elements
    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            *min_val = arr[low];
            *max_val = arr[high];
        } else {
            *min_val = arr[high];
            *max_val = arr[low];
        }
        return;
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;

    int left_min, left_max;
    int right_min, right_max;

    // Recursively find the minimum and maximum in the left half
    find_min_max(arr, low, mid, &left_min, &left_max);

    // Recursively find the minimum and maximum in the right half
    find_min_max(arr, mid + 1, high, &right_min, &right_max);

    // Combine the results to find the overall minimum and maximum
    *min_val = left_min < right_min ? left_min : right_min;
    *max_val = left_max > right_max ? left_max : right_max;
}

int main() {
    int arr[] = {3, 5, 1, 9, 2, 8, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int min_val, max_val;
    
    find_min_max(arr, 0, n - 1, &min_val, &max_val);
    
    printf("Minimum value in the array: %d\n", min_val);
    printf("Maximum value in the array: %d\n", max_val);
    
    return 0;
}
