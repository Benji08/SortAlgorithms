
#pragma once

template <typename Iterator>
void insertionSort(Iterator first, Iterator last)
{
    //TODO implement insertion sort
    for(Iterator i = first+1; i!=last && first != last; i++){
        int temp = *i;
        Iterator j = i;
        while (j != first && *(j-1) > temp){
            *j = *(j-1);
            j--;
        }
        *j = temp;
    }
}
