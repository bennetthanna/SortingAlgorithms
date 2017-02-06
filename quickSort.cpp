#include "sort.h"
#include <algorithm>

//make function to set pivot
int pivotList(vector <int> &v, int first, int last) {
    //set pivot to first value
    int pivotValue = v[first];
    //set index to first index
    int pivotPoint = first;
    //iterate through from the element after first through to the last
    for (int i = first + 1; i <= last; ++i) {
        //if the element is less than pivot value
        if (v[i] < pivotValue) {
            //move pivot index over 1
            pivotPoint = pivotPoint + 1;
            //swap the value at the new pivot index with the element
            swap(v[pivotPoint], v[i]);
        }
    }
    //swap the first element with the element at the pivot point
    swap(v[first], v[pivotPoint]);
    return pivotPoint;
}

//make quick sort function that takes 3 parameters
void myQuickSort(vector <int> &v, int first, int last) {
    //if the first index is less than the last
    if (first < last) {
        //set pivot to the point returned by previous function
        int pivot = pivotList(v, first, last);
        //recursively call function for each side of pivot
        myQuickSort(v, first, pivot - 1);
        myQuickSort(v, pivot + 1, last);
    }
}

void quickSort(vector <int> &v) {
    //call the self-made quick sort function
    myQuickSort(v, 0, v.size() - 1);
}
