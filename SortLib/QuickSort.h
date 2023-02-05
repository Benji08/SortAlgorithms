#pragma once
#include <algorithm>

template <typename Iterator>

//int partition(Iterator first, Iterator last){
//    int pivot = *(last - 1);
//    for(;first != last-1;first++){
//        if(*first <= pivot){
//            first++;
//        }
//    }
//}

void quickSort(Iterator first, Iterator last)
{
	//TODO implement quick sort
    if (distance(first, last) <= 1)
        return;

    int pivot = *first;
    Iterator left = first, right = last - 1;
    while (std::distance(left , right) > 0){
        while (std::distance(left, right) > 0 && *right >= pivot){
            --right;
        }
        *left = *right;
        while (std::distance(left, right) > 0 && *left <= pivot){
            ++left;
        }
        *right = *left;
    }
    *left = pivot;
    quickSort(first, left);
    quickSort(left + 1, last);
}