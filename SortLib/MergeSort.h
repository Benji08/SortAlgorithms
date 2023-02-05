#pragma once
#include <algorithm>


template <typename Iterator>
void merge(Iterator first,Iterator middle, Iterator last){

    std::vector<typename Iterator::value_type> tmp; //wektor pomocniczy
    Iterator left = first;
    Iterator right = middle;

    //pętla wprowadząjąca do wektora mniejszą z wartości
    //działa do momentu, gdy któryś z podzbiorów nie zostanie wprowadzony w całości
    while(left != middle && right != last){
        if (*left > *right){
            tmp.push_back(*right);
            right++;
        }
       else {
            tmp.push_back(*left);
            left++;
        }
    }
      //dopełnianie wektora niewykorzystanymi wartościami
      tmp.insert(tmp.end(), left, middle);
      tmp.insert(tmp.end(), right, last);

    //podmiana nieposortowanego zakresu wektora posorotowanym podzbiorem
    std::move(tmp.begin(), tmp.end(),first);

}

template <typename Iterator>
void mergeSort(Iterator first, Iterator last)
{
    int length = std::distance(first, last);
    if ( length <= 1)
        return;

    Iterator middle = first + (length/2);

    mergeSort(first, middle);
    mergeSort(middle, last);

    merge(first, middle, last);
}

