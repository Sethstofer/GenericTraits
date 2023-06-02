#include "quick_sort.h"
#include "GenericTraits.h"

//typedef void* (*func_ptr)();

void swap(GenericTraits **arr[], int a, int b)
{
    GenericTraits **temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void generic_qsort(GenericTraits **arr[], int left, int right) {
    if (left >= right) return;

    int (*cmp)() = (*arr[0])->cmp;   // `cmp` is a function that compares objects within `arr`
    int i = left + 1, j = right, pivot = left;

    while (i <= j) {
        while ( ((cmp(arr[i], arr[pivot]) < 0) || (cmp(arr[i], arr[j]) == 0)) && (i <= right) ) i++;
        while ( ((cmp(arr[j], arr[pivot]) > 0) || (cmp(arr[i], arr[j]) == 0)) && (j > left) ) j--;

        // ^ GenericTraits-using version of below
        // while ((arr[i] <= arr[pivot]) && (i <= right)) i++;
        // while ((arr[j] >= arr[pivot]) && (j > left)) j--;

        if (i < j)
        {
            // swap(&arr[i], &arr[j]);
            swap(arr, i, j);
        }
        else
        {
            // swap(&arr[pivot], &arr[j]);
            swap(arr, pivot, j);
        }
    }

    generic_qsort(arr, left, j - 1);
    generic_qsort(arr, j + 1, right);
}

void quick_sort(GenericTraits **array[], int n) {
    /* Your code here for sorting */
    generic_qsort(array, 0, n);
}
