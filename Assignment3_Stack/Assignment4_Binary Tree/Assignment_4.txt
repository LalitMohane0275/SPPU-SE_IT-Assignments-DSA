/*
Assignment 4
Title :- Binary Tree
Aim :- To create a expression tree and perform recursive and non recursive traversals
*/

#include <iostream>    // header file
#include <stack>       // stl - stack for non recursive traversals
using namespace std;

// Node structure for the binary tree
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Binary Tree class
class BinaryTree {
private:
    Node* root;

public:
    // Constructors and member functions
    BinaryTree();                            // default constructor
    BinaryTree(char c);                      // parameterized constructor
    Node* getRoot();                         // returns the root of the tree
    void inOrderRecursive(Node* temp);       // in-order traversal of the tree using recursion
    void preOrderRecursive(Node* temp);      // pre-order traversal of the tree using recursion
    void postOrderRecursive(Node* temp);     // post-order traversal of the tree using recursion
    void inOrderNonRecursive(Node* root);    // in-order traversal of the tree without recursion
    void preOrderNonRecursive(Node* root);   // pre-order traversal of the tree without recursion
    void postOrderNonRecursive(Node* root);  // post-order traversal of the tree without recursion
    void expressionTree(string postfix);     // creates expression tree of the given postfix expression
};

// Default constructor
BinaryTree::BinaryTree() {
    root = NULL;
}

// Parameterized constructor
BinaryTree::BinaryTree(char c) {
    Node* temp = new Node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = c;
    root = temp;
}

// Function to get the root of the tree
Node* BinaryTree::getRoot() {
    return this->root;
}

// In-order traversal using recursion
void BinaryTree::inOrderRecursive(Node* temp) {
    if (!temp)
        return;
    inOrderRecursive(temp->left);
    cout << temp->data << " ";
    inOrderRecursive(temp->right);
}

// Pre-order traversal using recursion
void BinaryTree::preOrderRecursive(Node* temp) {
    if (!temp)
        return;
    cout << temp->data << " ";
    preOrderRecursive(temp->left);
    preOrderRecursive(temp->right);
}

// Post-order traversal using recursion
void BinaryTree::postOrderRecursive(Node* temp) {
    if (!temp)
        return;
    postOrderRecursive(temp->left);
    postOrderRecursive(temp->right);
    cout << temp->data << " ";
}

// In-order traversal without recursion
void BinaryTree::inOrderNonRecursive(Node* root) {
    if (!root)
        return;

    stack<Node*> st;
    Node* t = root;

    while (t != nullptr || !st.empty()) {
        while (t != nullptr) {
            st.push(t);
            t = t->left;
        }
        t = st.top();
        st.pop();
        cout << t->data << " ";

        t = t->right;
    }

    cout << endl;
}

// Pre-order traversal without recursion
void BinaryTree::preOrderNonRecursive(Node* root) {
    if (!root)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* t = s.top();
        s.pop();
        cout << t->data << " ";

        if (t->right)
            s.push(t->right);
        if (t->left)
            s.push(t->left);
    }

    cout << endl;
}

// Post-order traversal without recursion
void BinaryTree::postOrderNonRecursive(Node* root) {
    if (!root)
        return;

    stack<Node*> S1, S2;
    S1.push(root);

    while (!S1.empty()) {
        Node* temp = S1.top();
        S1.pop();
        S2.push(temp);

        if (temp->left)
            S1.push(temp->left);
        if (temp->right)
            S1.push(temp->right);
    }

    while (!S2.empty()) {
        cout << S2.top()->data << " ";
        S2.pop();
    }
    cout << endl;
}

// Function to create an expression tree from a postfix expression
void BinaryTree::expressionTree(string postfix) {
    stack<Node*> S2;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        Node* temp = new Node;
        temp->data = c;
        temp->right = NULL;
        temp->left = NULL;

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Current character is an operator
            Node* second = S2.top();
            S2.pop();
            temp->right = second;
            Node* first = S2.top();
            temp->left = first;
            S2.pop();
        }

        S2.push(temp);
    }

    root = S2.top();
    S2.pop();
}

// Main function
int main() {
    // Flag to control the loop
    bool flag = true;
    
    // Loop until the user chooses to exit
    while (flag) {
        // Display menu options
        cout << "Menu:\n";
        cout << "1. Enter postfix equation\n";
        cout << "2. Print pre-order traversal (Recursive)\n";
        cout << "3. Print post-order traversal (Recursive)\n";
        cout << "4. Print in-order traversal (Recursive)\n";
        cout << "5. Print pre-order traversal (Non Recursive)\n";
        cout << "6. Print post-order traversal (Non Recursive)\n";
        cout << "7. Print in-order traversal (Non Recursive)\n";
        cout << "8. Exit\n";

        // User input for menu choice
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Create a new BinaryTree object and a pointer to the root node
        BinaryTree B1;
        Node* root;

        // Perform actions based on user choice
        switch (choice) {
            case 1: {
                // Option to enter a postfix equation
                string eqn;
                cout << "Enter postfix equation: ";
                cin >> eqn;
                B1.expressionTree(eqn);
                root = B1.getRoot();
                break;
            }
            case 2: {
                // Option to print pre-order traversal using recursion
                cout << "Pre order traversal(Recursive): ";
                B1.preOrderRecursive(root);
                cout << endl;
                break;
            }
            case 3: {
                // Option to print post-order traversal using recursion
                cout << "Post order traversal(Recursive): ";
                B1.postOrderRecursive(root);
                cout << endl;
                break;
            }
            case 4: {
                // Option to print in-order traversal using recursion
                cout << "In order traversal(Recursive): ";
                B1.inOrderRecursive(root);
                cout << endl;
                break;
            }
            case 5: {
                // Option to print pre-order traversal without recursion
                cout << "Pre order traversal(Non Recursive): ";
                B1.preOrderNonRecursive(root);
                break;
            }
            case 6: {
                // Option to print post-order traversal without recursion
                cout << "Post order traversal(Non Recursive): ";
                B1.postOrderNonRecursive(root);
                break;
            }
            case 7: {
                // Option to print in-order traversal without recursion
                cout << "In order traversal(Non Recursive): ";
                B1.inOrderNonRecursive(root);
                break;
            }
            case 8: {
                // Option to exit the program
                flag = false;
                break;
            }
            default: {
                // Displayed for an invalid menu choice
                cout << "Invalid choice\n";
            }
        }
        cout << endl;
    }
    return 0;
}

