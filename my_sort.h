// Mimic the std:: version

#ifndef MY_SORT_H
#define MY_SORT_H

#include "MyHeap.h"

//Function to sort the array in descending order
template <typename T>
void my_sort(T * array, int size)
{
  MyHeap<T> descending_sort(array, size); //declaration to MyHeap class type
                                          //varaible

  for(int i = 0; descending_sort.size() > 0; i++)//goes to each index and check
  {
    array[i] = descending_sort.top(); // current index is equal to top element
    descending_sort.pop(); //removes/pop the element
  }
}

#endif
