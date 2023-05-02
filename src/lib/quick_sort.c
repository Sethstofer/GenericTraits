#include "quick_sort.h"
#include "GenericTraits.h"

void quick_sort(GenericTraits **array[], int n) {
    /* Your code here for sorting */

    // qsort()

}

/* ** ORIGINAL FUNC FOR INTEGER ARRAY **
void qsort(int *arr, int left, int right) {
    if (left >= right) return;
    int i = left + 1, j = right, pivot = left;
    while (i <= j) {
        while ((arr[i] <= arr[pivot]) && (i <= right)) i++;
        while ((arr[j] >= arr[pivot]) && (j > left)) j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            swap(&arr[pivot], &arr[j]);
    }
    basic_qsort(arr, left, j - 1);
    basic_qsort(arr, j + 1, right);
}
*/