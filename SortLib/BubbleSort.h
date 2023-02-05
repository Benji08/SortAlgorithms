#pragma once
#include <algorithm>


template <typename Iterator>
void bubbleSort(Iterator first, Iterator last)
{
    bool swap_count = true;
    Iterator temp = last - 1;
    for(Iterator i = first; i != last && swap_count; i++){
        swap_count = false;
        for(Iterator j = first; j != temp; j++){
            if(*j>*(j+1)) {
                std::swap(*j, *(j+1));
                swap_count = true;
            }
        }
    }

}