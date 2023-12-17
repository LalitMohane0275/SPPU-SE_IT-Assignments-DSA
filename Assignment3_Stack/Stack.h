/*
stack : -header file for assignment 3
        -used template
        - used linked list for implementation
*/
#include <iostream>
using namespace std;

// struct Node: to use linked list for implementation
template <typename T> // generics: used template
struct Node
{
  T data;
  Node *next;
};

// class StackLL: stack using linked list
template <typename T> // generics: used template
class StackLL
{
private:
  Node<T> *topOfTheStack;

public:
  StackLL();              // default constructor
  Node<T> *newNode();     // creates a new node and returns a pointer to it
  Node<T> *newNode(T x);  // creates a new node with data and returns a pointer to it
  bool isEmpty();         // returns true if the linked list is empty
  bool isFull();          // return true if the linked list is full;
  bool push_back(T data); // inserts a new element at the top of the stack
  T pop();                // pop the element at the top and returns it
  T top();                // returns the element at the top
  void displayLL();       // displays all elements present in the queue
};

template <typename T>
StackLL<T>::StackLL()
{
  topOfTheStack = NULL;
}

template <typename T>
Node<T> *StackLL<T>::newNode()
{
  Node<T> *temp = new Node<T>();
  return temp;
}

template <typename T>
Node<T> *StackLL<T>::newNode(T x)
{ // you can have elements passed
  Node<T> *temp = new Node<T>();
  temp->data = x;
  temp->next = NULL;
  return temp;
}

template <typename T>
bool StackLL<T>::isEmpty()
{
  if (topOfTheStack == NULL)
    return true;
  else
    return false;
}

template <typename T>
bool StackLL<T>::isFull()
{
  // Specify your condition for a full stack here
  // For now, let's assume the stack is never full
  return false;
}

template <typename T>
bool StackLL<T>::push_back(T data)
{
  if (isFull())
  {
    return false;
  }
  else
  {
    Node<T> *temp = newNode(data);
    temp->next = topOfTheStack;
    topOfTheStack = temp;
    return true;
  }
}

template <typename T>
T StackLL<T>::pop()
{
  if (isEmpty())
  {
    return T(); // return a default-constructed T for an empty stack
  }
  T data1;
  Node<T> *temp1 = topOfTheStack;
  topOfTheStack = topOfTheStack->next;
  data1 = temp1->data;
  delete temp1;
  return data1;
}

template <typename T>
T StackLL<T>::top()
{
  if (isEmpty())
  {
    return T();
  }
  else
  {
    return topOfTheStack->data;
  }
}

template <typename T>
void StackLL<T>::displayLL()
{
  Node<T> *temp2 = topOfTheStack;
  while (temp2 != NULL)
  {
    cout << temp2->data << " ";
    temp2 = temp2->next;
  }
  cout << endl;
}

/* main fuction to test stack*/
/*
int menu()
{
  cout << "\n_____MENU_____" << endl;
  cout << "Enter your choice : " << endl;
  cout << "1 - push/insert/enqueue\n2 - delete/dequeue/pop\n3 - element at top\n4 - display\n5 - exit" << endl;
  int choice;
  cin >> choice;
  return choice;
}

int main()
{
  StackLL<char> S; // Specify the type you want to use (e.g., char)

  bool flag = true;
  while (flag)
  {
    int choice = menu();
    switch (choice)
    {
    case 1:
      char ins;
      bool Check;
      cout << "Enter the data you want to insert : " << endl;
      cin >> ins;
      Check = S.push_back(ins);
      if (Check)
      {
        cout << "Element enqueued successfully." << endl;
      }
      else
      {
        cout << "Cannot enter your element" << endl;
      }
      break;
    case 2:
      char del;
      del = S.pop();
      if (del == '\0')
      {
        cout << "Cannot delete the element as the queue is full" << endl;
      }
      else
      {
        cout << "Element " << del << " is dequeued successfully." << endl;
      }
      break;
    case 3:
      char topC;
      topC = S.top();
      if (topC == '\0')
      {
        cout << "The queue is empty" << endl;
      }
      else
      {
        cout << "The element at the top : " << topC << endl;
      }
      break;
    case 4:
      S.displayLL();
      break;
    case 5:
      flag = false;
      break;
    }
  }

  return 0;
} */