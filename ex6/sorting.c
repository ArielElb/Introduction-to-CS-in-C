/***********************
* Name: Ariel Elbaz.
* ID: 213073497.
* Assignment: ex_5.
***********************/

#include "sorting.h"


/*********************************************************************************************************************
* Function name: quicksort
* Input: void* arr, int start, int stop, void(*swap)(void*, int, int), int(*compare)(void*, int, int)
* Output: void
* Function Operation: the function select the pivot from the array and making partitions of the other elements into two
 * sub-arrays,depending if they are less than or greater than the pivot.
 * and sorting the sub-arrays in recursive until the array is sorted.
**********************************************************************************************************************/
void quicksort(void* arr, int start, int stop, void(*swap)(void*, int, int), int(*compare)(void*, int, int)) {
    /*
     * if there is only one element -return
     */
    if (start >= stop - 1) {
        return;
    }
    //define the pivot as the first index of the array.
    int pivot = start;
    int j = start;
    /*
     * iterate through the loop and swap the element
     */
    for (int i = start + 1; i < stop; i++)  {
        // TODO : SWITCH PIVOT AND I AND FIX
        if (compare(arr,i,pivot) < 0) {
            j++;
            //if the indices arnt equal , swap the element.
            if (i != j) {
                swap(arr, i, j);
            }
        }
    }
    swap(arr, start, j);
    //recursive call the function
    quicksort(arr, start, j,swap,compare);
    quicksort(arr, j + 1, stop,swap,compare);
}