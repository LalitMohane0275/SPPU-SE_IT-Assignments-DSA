/*
Assignment 2
Title :- Circular Queue
Aim :- To implement circular queue using arrays and perform enqueue, dequeue and display operations.
*/

#include <iostream>    // header file
#include <climits>     // for using INT_MAX and INT_MIN
#include </home/lalit/Documents/Codes/CPlusPlus/23324/GitHub/Assignment2_Circular Queue/Queue.h>
                        // custom header file of circular queue
using namespace std;

int menu()             // menu for user
{
	cout << "_______MENU_______" << endl;
	cout << "1 - enqueue\n2 - dequeue\n3 - display\n4 - exit\n";
	cout << "Enter your choice : " << endl;
	int choice;
	cin >> choice;
	return choice;
}

int main()            // main fuction
{
	Queue Q;           
	while (1)
	{
		int ch;
		ch = menu();
		switch (ch)
		{
		case 1:        // case 1 : insert/enqueue element
			int enq;
			cout << "Enter the element you want to enqueue : " << endl;
			cin >> enq;
			bool check;
			check = Q.enqueue(enq);
			if (check)
			{
				cout << "The element is enqueued successfully" << endl;
			}
			else
			{
				cout << "Cannot insert element as the queue is full" << endl;
			}
			break;
		case 2:           // case 2 : delete/dequeue element
			int dqe;
			dqe = Q.dequeue();
			if (dqe == INT_MIN)
			{
				cout << "dequeue operation failed, the queue is full." << endl;
			}
			else
			{
				cout << "dequeue operation successful, element " << dqe << " dequeued." << endl;
			}
			break;
		case 3:          // case 3 : display elements in the queue
			Q.display();
			break;
		case 4:          // case 4 : exit from program
			exit(0);
			break;
		default :        // invalid case
			cout << "Invalid case, please enter valid case:)" << endl;
			break;
		}
	}
	return 0;
}
