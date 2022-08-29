#include <iostream>
using namespace std;

template <class T>
class ArrayABT
{
private:
  T *arr;
  int size;
  int length;

  T element = 0;
  int index = 0;

  void Swap(T *x, T *y);

public:
  void Display();
  int Append(T element);
  int Insert(T element, int index);
  int Delete(int index);
  int LinearSearch(T element);

  ArrayABT()
  {
    arr = new T[10];
    length = 0;
  }

  ArrayABT(int sz)
  {
    size = sz;
    arr = new T[sz];
    length = 0;
  }

  ~ArrayABT()
  {
    delete[] arr;
  }
};

template <class T>
void ArrayABT<T>::Swap(T *x, T *y)
{
  T temp = *x;
  *x = *y;
  *y = temp;
}

template <class T>
int ArrayABT<T>::LinearSearch(T element)
{
  for (int i = 0; i < length; i++)
  {
    if (arr[i] == element)
    {
      Swap(&arr[i], &arr[i - 1]);
      return i;
    }
  }

  return -1;
}

template <class T>
void ArrayABT<T>::Display()
{
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << endl;
  }
}

template <class T>
int ArrayABT<T>::Append(T element)
{
  if (length < size)
  {
    arr[length++] = element;
    return 1;
  }
  else
    return 0;
}

template <class T>
int ArrayABT<T>::Insert(T element, int index)
{
  if (index >= 0 && index <= length)
  {
    for (int i = length; i > index; i--)
    {
      arr[i] = arr[i - 1];
    }
    arr[index] = element;
    length++;
    return 1;
  }
  else
    return 0;
}

template <class T>
int ArrayABT<T>::Delete(int index)
{
  if (index >= 0 && index < length)
  {
    for (int i = index; i < length - 1; i++)
    {
      arr[i] = arr[i + 1];
    }
    length--;
    return 1;
  }
  else
    return 0;
}

int MenuDriver()
{
  int size = 0;
  int input = 0;
  int output = 0;
  int index = 0;

  cout << "Enter size of Array" << endl;
  cin >> size;
  ArrayABT<char> arr(size);
  char element;
  do
  {
    cout << "Menu Driver program" << endl;
    cout << "1. Append" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete" << endl;
    cout << "4. Search" << endl;
    cout << "5. Display" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice" << endl;
    cin >> input;

    switch (input)
    {
    case 1:
      cout << "Enter an element to append" << endl;
      cin >> element;
      output = arr.Append(element);
      if (output == 1)
        cout << "Element added" << endl;
      else
        cout << "No space in array" << endl;
      break;
    case 2:
      cout << "Enter an element & index" << endl;
      cin >> element;
      cin >> index;
      output = arr.Insert(element, index);
      if (output == 1)
        cout << "New element inserted" << endl;
      else
        cout << "Invalid values\n";
      break;
    case 3:
      cout << "Enter index to delete element from" << endl;
      cin >> index;
      output = arr.Delete(index);
      if (output == 1)
        cout << "Element deleted" << endl;
      else
        cout << "Invalid index value" << endl;
      break;
    case 4:
      cout << "Enter element to search" << endl;
      cin >> element;
      output = arr.LinearSearch(element);
      if (output != -1)
        cout << "The element is at index " << output << endl;
      else
        cout << "Element not found.";
      break;
    case 5:
      cout << "The elements in array are: " << endl;
      arr.Display();
      break;
    }

  } while (input < 6);

  return 0;
}

int main()
{
  // char *p = new char[10];
  // p[0] = 'a';
  // p[1] = 'b';

  MenuDriver();
  // ArrayABT<char> arr(10);

  // arr.Append('d');
  // arr.Append('c');
  // arr.Display();

  return 0;
}