//MyHeap Header file
#ifndef MYHEAP_H
#define MYHEAP_H

using namespace std;

//Function for setting my_id to MST username
void get_identity(std::string &my_id)
{
  my_id = "hdpg4c";
}

//Function to swap values
template <typename T>
void swap(T &a, T &b)
{
  //swaps two numbers
  T c = a;
  a = b;
  b = c;
}

//My Heap class
template <typename T>
class MyHeap
{
  private:
    //vairables
    T *m_data;
    int reserved_size;
    int data_size;

  public:

    //constructor
    MyHeap()
    {
      //default array to nullptr
      m_data = nullptr;
      reserved_size = 0; //defaults reserved_size to 0
      data_size = 0; //defaults the data size to 0
    }

    //Deconstructor
    ~MyHeap()
    {
      delete[] m_data; //deletes the m_data array
    }

    MyHeap(T arr[],  int size)
    {
      if(size > 0) //if size is greater than 0
      {
        data_size = size; //data_size is set to size
        m_data = new T[data_size * 2];//data_size is increased times 2
        reserved_size = data_size * 2; //reserved size set to doubled data size
        for(int i = 0; i < data_size; i++)
        {
          m_data[i] = arr[i];
        }
        heapify(); //calls the heapify function
      }
    }

    //copy constructor
    MyHeap(const MyHeap<T> &source)
    {
       //sets the source capacity to reserved_size
      reserved_size = source.reserved_size;
      data_size = source.data_size; //sets the data_size to source size

      m_data = new T[reserved_size];

      for(int i = 0; i < reserved_size; i++)
        m_data[i] = source.m_data[i];
    }

    MyHeap<T> & operator=(const MyHeap<T> & source)
    {
      //sets reserved_size to source reserved_size
      //sets data_size to source data_size
      data_size = source.data_size;
      reserved_size = source.reserved_size;

      delete[] m_data; //deallocate the elements in m_data array

      m_data = new T[reserved_size]; //new pointer

      //iterates for each reserved_size and
      //sets data arrray to source data
      for(int i = 0; i < reserved_size; i++)
        m_data[i] = source.m_data[i];

      return *this;
    }

    void heapify()
    {
      int index = reserved_size - 1; //reserved size decremented by 1
      int index_size = 0;

      int n = reserved_size / 2; //half of reserved_size

      T temp; //new variable of type T

      for(int i = 1; i < reserved_size; i++)
      {
        temp = m_data[i]; //temp set to m_data index

        int j = i - 1; //i minus 1

        while(j >= 0 && m_data[j] > temp)
        {
          m_data[j + 1] = m_data[j];
          j--; //j is decremented by 1
        }

        m_data[j + 1] = temp; //m_data j + 1 is set to temp(m_data i)
      }

      for(int k = 0; k < n; k++)
      {
        //swaps the two data with different index
        std::swap(m_data[index_size], m_data[index]);

        index_size = index_size + 1; //index size is incremented by 1
        index = index - 1; //index is decremented by 1
      }
    }

    //Function to remove the element
    void pop()
    {
      if(data_size == 0) //s size is 0, then does nothing
        return;

      if(data_size > 0) //if size greater than 0
      {
        for(int i = 0; i < data_size-1; i++) //iterates
          m_data[i] = m_data[i + 1]; //set the index to next index in array

        data_size--; //decremented
      }

      if(data_size <= reserved_size/4) //data size is less than i/4 of reserved_size
        shrink_to_fit();//calls the shrink_to_fit function
    }

    //Funciton to appends the value x to the end of an MyHeap
    void push(const T& x)
    {
      int size = data_size + 1; //increments the data size

      if(data_size >= reserved_size) //if data size is greater than max size
        reserve(size); //calls the reserve function

      if(data_size <= 0) //data size is less or equal to 0
        reserve(size); //calls the reserve funciton

      m_data[data_size++] = x; //m_data with index of incremented data size is
                               //set to X

      heapify(); //calls the heapify funciton

      return;
    }

    //Function to reserve size
    void reserve(int new_cap)
    {
      //Increases max_size to new_cap if new_cap > max_size
      if(new_cap > reserved_size)
      {
        T *data = m_data; //new pointer of type T
        m_data = new T[new_cap];
        for(int i = 0; i < data_size; i++)
        {
          if(data != nullptr) //checks if data is not equal to nullptr
          m_data[i] = data[i]; //if yes, then sets m_data[i] to pointer data[i]
        }
          delete[] data; //deletes the array/memory
          reserved_size = new_cap; //sets reserved size to new_cap value
      }
    }

    //Function should shrink such that the array is 2x as big as the data.
    void shrink_to_fit()
    {
      int new_dataSize = data_size * 2; //data_size is increased times 2
      T *array = new T[new_dataSize]; //new pointer array

      for(int i = 0; i < data_size; i++) //iterates through each data_size
      {
        array[i] = m_data[i];
      }
      reserved_size = new_dataSize; //reserved_size equal to new data size value
      delete[] m_data; //deletes the array
      m_data = nullptr;
      m_data = array;
    }

    //Funciton returns the max size of the array
    int capacity()
    {
      return reserved_size;
    }

    //Function returns the size of the actual data stored in the array list
    int size() const
    {
      return data_size;
    }

    //Function to empty the MyHeap
    bool empty() const
    {
      if(data_size == 0)//if data size array is equal to 0, then it is not empty
        return true;

      return false; //returns false if list is not empty
    }

    //Function clears the MyHeap
    void clear()
    {
      //current size and storage is set back to 0
      data_size = 0;
      reserved_size = 0;

      delete[] m_data; //deallocate the elements in m_data array
      m_data = nullptr;  //m_data is set to null pointer
    }

    //Function to print the results
    void print()
    {
      for(int i = 0; i < size(); i++)
        cout << m_data[i] << endl;
    }

    //Function returns the first element in the MyHeap array
    T & top() const
    {
      return m_data[0];
    }

};

#endif
