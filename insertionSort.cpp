#include "sort.h"

void insertionSort(vector <int> &v)
{
    int newElement;
    int location;
    
    //for each element in the vector
    for (int i = 1; i < v.size(); ++i) {
        //set element to look at
        newElement = v[i];
        //set location one back
        location = i - 1;
        //while location is greater than or equal to zero and the element at the location is
        //greater than the element you're looking at
        while (location >= 0 && v[location] > newElement) {
            //set the element at the location to to location + 1
            v[location+1] = v[location];
            //decrement location
            location = location - 1;
        }
        //set the location + 1 to the element you're looking at
        v[location+1] = newElement;
    }
}
