/*
Assignment 6
Title :- Threaded Binary Tree
Aim :- To implement tbt and perform inorder traversal
*/

#include <bits/stdc++.h>     // header file
using namespace std;

// Node structure for Threaded Binary Tree
struct Node {
    Node *left, *right;
    int data, lthread, rthread;
};

// Class for Threaded Binary Tree
class TBT {
private:
    Node *root;

public:
    TBT();                               // default constructor
    Node *insertNode(int data);          // inserts a node in the threaded binary tree
    Node *inOrderSuccessor(Node *t);     // finds and returns inorder successor of the node t and returns pointer of it
    void inOrderTraversal(Node *root);   // in-order traversal of the threaded binary tree without stack and recursion
    void preOrderTraversal(Node *root);  // pre-order traversal of the threaded binary tree without stack and recursion
    Node* getRoot();                     // returns the root of threaded binary tree
};

// TBT class constructor
TBT::TBT() {
    root = NULL;
}

// Function to insert a node in the threaded binary tree
Node* TBT::insertNode(int data) {
    Node *temp = root;
    Node *parent = NULL;
    while (temp) {
        if (data == (temp->data)) {
            cout << "Data already exists" << endl;
            return root;
        }
        parent = temp;
        if (data > temp->data) {
            if (temp->rthread == 0) {
                temp = temp->right;
            } else {
                break;
            }
        } else {
            if (temp->lthread == 0) {
                temp = temp->left;
            } else {
                break;
            }
        }
    }
    Node *newNode = new Node;
    newNode->data = data;
    newNode->lthread = 1, newNode->rthread = 1;
    if (!parent) {
        root = newNode;
        newNode->left = NULL;
        newNode->right = NULL;
    } else if (data < (parent->data)) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->lthread = 0;
        parent->left = newNode;
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->rthread = 0;
        parent->right = newNode;
    }
    return root;
}

// Function to find and return the inorder successor of a given node
Node* TBT::inOrderSuccessor(Node* t) {
    if (t->rthread == 1) {
        return t->right;
    }
    t = t->right;
    while (t->lthread == 0) {
        t = t->left;
    }
    return t;
}

// Function to perform in-order traversal of the threaded binary tree without recursion
void TBT::inOrderTraversal(Node* root) {
    cout << "INORDER TRAVERSAL\n";
    if (!root) {
        cout << "Tree is Empty" << endl;
    }
    struct Node *temp = root;
    while (temp->lthread == 0) {
        temp = temp->left;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = inOrderSuccessor(temp);
    }
    cout << endl;
}

// Function to perform pre-order traversal of the threaded binary tree without recursion
void TBT::preOrderTraversal(Node* root) {
    cout << "PREORDER TRAVERSAL\n";
    if (!root) {
        cout << "Tree is Empty" << endl;
        return;
    }
    Node *temp = root;
    while (temp) {
        cout << temp->data << " ";
        while (temp->lthread == 0) {
            temp = temp->left;
            cout << temp->data << " ";
        }
        while (temp->rthread == 1 && temp->right) {
            temp = temp->right;
        }
        temp = temp->right;
    }
    cout << endl;
}

// Function to get the root of the threaded binary tree
Node* TBT::getRoot() {
    return this->root;
}

// Main function
int main() {
    TBT tree;

    // Input number of nodes
    cout << "Enter the number of nodes to be inserted: " << endl;
    int nodes;
    cin >> nodes;

    // Ensure at least one node is inserted
    while (nodes <= 0) {
        cout << "Enter at least one node to insert." << endl;
        cout << "Enter the number of nodes to be inserted: " << endl;
        cin >> nodes;
    }

    cout << "Enter " << nodes << " elements: \n";

    // Insert nodes into the threaded binary tree
    while (nodes--) {
        int data;
        cin >> data;
        tree.insertNode(data);
    }

    Node* root = tree.getRoot();

    // User menu for operations
    while (true) {
        cout << "\nChoose Your Operation:\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree - PREORDER TRAVERSAL \n";
        cout << "3. Display Tree - INORDER TRAVERSAL\n";
        cout << "Press 4 to exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1: {
                // Insert a node into the threaded binary tree
                cout << "Enter the data : " << endl;
                int data;
                cin >> data;
                tree.insertNode(data);
                break;
            }
            case 2:
                // Display tree using pre-order traversal
                tree.preOrderTraversal(root);
                break;
            case 3:
                // Display tree using in-order traversal
                tree.inOrderTraversal(root);
                break;
            case 4:
                // Exit the program
                cout << "Thank You! " << endl;
                return 0;
            default:
                // Invalid choice
                cout << "Invalid Choice! Please re-enter the choice : " << endl;
        }
    }

    return 0;
}

