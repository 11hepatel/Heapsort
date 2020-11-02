// Mimic the std:: version
#ifndef MY_IS_SORTED_H
#define MY_IS_SORTED_H

//Function take the same two parameters, and return a bool,
// true if the array is sorted max-first, and false if not.
template <typename T>
bool my_is_sorted(T array[], int size)
{
  int value = size - 1; //declares variable of decremented size
  int count = 0; //start index

  while(count < value) // index is less than the decremented size
  {
    if(array[count] < array[count + 1]) //if index is less then next index
      return false; //returns false

    count++; //increments to the next index
  }
  return true; //returns true
}

#endif
