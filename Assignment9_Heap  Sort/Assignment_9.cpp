/*
Assignment 9
Title : Heap Sort
Aim : To perform heap sort using max and min heap
*/

#include <iostream>     // header file
using namespace std;

// Class definition for the heap
class heap {
private:
    int *arr;
    int size;

public:
    // Function to print the elements in the heap
    void printHeap(int arr[], int size);
    
    // Function to heapify the array in ascending order
    void heapifyAscending(int arr[], int size, int i);
    
    // Function to heapify the array in descending order
    void heapifyDescending(int arr[], int size, int i);
    
    // Function to perform heap sort in ascending order
    void heapSortAscending(int arr[], int size);
    
    // Function to perform heap sort in descending order
    void heapSortDescending(int arr[], int size);
};

// Function to print the elements in the heap
void heap::printHeap(int arr[], int size) {
    cout << "Elements in the heap are : \n";
    for (int index = 0; index < size; index++) {
        cout << arr[index] << "  ";
    }
    cout << endl;
}

// Function to heapify the array in ascending order
void heap::heapifyAscending(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyAscending(arr, size, largest);
    }
}

// Function to heapify the array in descending order
void heap::heapifyDescending(int arr[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyDescending(arr, size, smallest);
    }
}

// Function to perform heap sort in ascending order
void heap::heapSortAscending(int arr[], int size) {
    for(int i = (size / 2) - 1; i >= 0; i--){
        heapifyAscending(arr, size, i);
    }
    
    for(int i = size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapifyAscending(arr, size, 0);
    }
}

// Function to perform heap sort in descending order
void heap::heapSortDescending(int arr[], int size) {
    for(int i = (size / 2) - 1; i >= 0; i--){
        heapifyDescending(arr, size, i);
    }
    
    for(int i = size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapifyDescending(arr, size, 0);
    }
}

int main() {
    heap h;
    cout << "Enter no of elements : " << endl;
    int n;    // size of heap
    cin >> n;  // input for size
    int arr[n];
    cout << "Enter the " << n << " elements : " << endl;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];   // input for data
    }

    cout << "Heap is successfully created :  \n";
    h.printHeap(arr, n);

    while(true){
        cout << "\n________MENU____________\n";
        cout << "1 - Sort Heap => Ascending order\n2 - Sort Heap => Descending order\n3 - Display Heap\n4 - exit\n";
        cout << "Enter your choice : " << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                // Sort the heap in ascending order
                h.heapSortAscending(arr, n);
                cout << "Heap is sorted in ascending order!!" << endl;
                break;
            case 2:
                // Sort the heap in descending order
                h.heapSortDescending(arr, n);
                cout << "Heap is sorted in descending order!!" << endl;
                break;
            case 3:
                // Display the current state of the heap
                h.printHeap(arr, n);
                break;
            case 4:
                // Exit the program
                cout << "Thank you for using the program!" << endl;
                exit(0);
                break;
            default:
                // Invalid choice
                cout << "Invalid choice, please try again :)" << endl;
                break;
        }
    }
    return 0;
}

