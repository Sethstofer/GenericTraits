#include "quick_sort.h"
#include "GenericTraits.h"

void swap(GenericTraits **arr[], int a, int b)
{
    GenericTraits **temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(GenericTraits **arr[], int left, int right)
{
    int i = left - 1;

    int (*cmp)() = (*arr[0])->cmp;   // function ptr to compare objects within `arr`

    for (int j = left; j < right; j++)
    {
        if ((cmp(arr[j], arr[right]) > 0) || (cmp(arr[j], arr[right]) == 0))
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, (i + 1), right);

    return (i + 1);
}

void quickSort(GenericTraits **arr[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);

        quickSort(arr, left, (pivot - 1));
        quickSort(arr, (pivot + 1), right);
    }
}

void quick_sort(GenericTraits **array[], int n) {
    /* Your code here for sorting */
    quickSort(array, 0, n - 1);
}
