/*
header file for Assignment2
*/

#include <iostream> // header file
#include <climits>  // for using INT_MAX and INT_MIN
using namespace std;

// class Queue :- implementation of circular queue
class Queue
{
private:
  int rear; // variables
  int front;
  int queue[10] = {0};

public:
  Queue();

  bool isFull();             // returns true if queue if full
  bool isEmpty();            // returns true if queue is empty
  bool enqueue(int element); // inserts an element from the rear end of the queue
  int dequeue();             // deletes the element from front end in queue and returns it
  void display();            // displays elements present in the queue
};

Queue ::Queue()
{
  front = 0;
  rear = 0;
}

bool Queue ::isFull()
{
  if (front == (rear + 1) % 10)
    return true;
  else
    return false;
}

bool Queue ::isEmpty()
{
  if (rear == front)
    return true;
  else
    return false;
}

/*---------------ENQUEUE-----------------*/
bool Queue ::enqueue(int element)
{
  if (!isFull())
  {
    queue[rear] = element;
    rear = (rear + 1) % 10;
    return true;
  }
  else
  {
    return false;
  }
}

/*---------------DEQUEUE-----------------*/
int Queue ::dequeue()
{
  if (!isEmpty())
  {
    front = (front + 1) % 10;
    return queue[(front - 1) % 10];
  }
  else
  {
    return INT_MIN;
  }
}

/*---------------DISPLAY-----------------*/
void Queue ::display()
{
  cout << "At front\t" << front << "\t" << rear - 1 << "\t" << queue[front] << endl;
  cout << "At rear  \t" << front << "\t" << rear - 1 << "\t" << queue[rear - 1] << endl;
  cout << "All from front\t" << front << "\t" << rear - 1 << "\t";
  for (int i = front; i < rear; i = (i + 1) % 10)
  {
    cout << queue[i] << " ";
  }
  cout << endl
       << "All from rear\t" << front << "\t" << rear - 1 << "\t";
  for (int j = rear; j > front; j = (j - 1) % 10)
  {
    cout << queue[j - 1] << " ";
  }
  cout << endl;
}

/*test the queue with following main fuction if required*/
/*
int menu(){
  cout << "_______MENU_______" << endl;
  cout << "1 - enqueue\n2 - dequeue\n3 - display\n4 - exit\n";
  cout << "Enter your choice : " << endl;
  int choice;
  cin >> choice;
  return choice;
}

int main(){
  Queue Q;
  //Q.enqueue(2);
  //Q.enqueue(3);
  //int x = Q.dequeue();
  //int y = Q.dequeue();
  //Q.display();

  while(1){
      int ch;
      ch = menu();
      switch(ch){
  case 1:
    int enq;
    cout << "Enter the element you want to enqueue : "  << endl;
    cin >> enq;
    Q.enqueue(enq);
    break;
  case 2:
    int dqe;
    dqe = Q.dequeue();
    if(dqe == -9){
      cout << "dequeue operation failed, the queue is full." << endl;
    }
    else{
      cout << "dequeue operation successful, element " << dqe << " dequeued." << endl;
    }
    break;
  case 3:
    Q.display();
    break;
  case 4:
    exit(0);
      }
  }
  return 0;
}*/
