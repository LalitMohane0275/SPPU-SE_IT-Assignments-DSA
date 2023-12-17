/*
Assignment 3
Title :- Stack
Aim :- To convert a infix expression to postfix and prefix equation and evaluation of the same
*/

#include <iostream> // header file
#include <climits>  // for using INT_MAX and INT_MIN
#include <cmath>    // for pow operation
#include </home/lalit/Documents/Codes/CPlusPlus/23324/GitHub/Assignment3_Stack/Stack.h>
// custom header file : stack

using namespace std;

// struct for paring operand and its value
struct operandval
{
    char operand1;
    int val1;
};

// class ConvertEvaluate : for converting infix expression to postfix and prefix and its evaluation
class ConvertEvaluate
{
private:
    StackLL<char> stack_1;
    string postfix;
    string prefix;
    operandval arr[100];

public:
    int incomingPriority(char ele);         // returns the incoming priority of the operator
    int inStackPriority(char ele);          // returns the instack priority of the operator
    bool isoperand(char ele);               // returns true if the character is an operand
    bool isoperator(char ele);              // returns true if the character is an operator
    void printArray();                      // prints the postfix array of characters
    string postfixConversion(string infix); // returns the posfix string
    string prefixConversion(string infix);  // returns the prefix string
    int EvaluationPost();                   // evaluates postfix expression
    int EvaluationPre();                    // evaluates prefix expression
};

int ConvertEvaluate ::incomingPriority(char ele)
{
    if (ele == '(')
        return 4;
    else if (ele == '^')
        return 3;
    else if (ele == '*' || ele == '/')
        return 2;
    else if (ele == '+' || ele == '-')
        return 1;
    else
        return -1;
}

int ConvertEvaluate ::inStackPriority(char ele)
{
    if (ele == '(')
        return 0;
    else if (ele == '^')
        return 3;
    else if (ele == '*' || ele == '/')
        return 2;
    else if (ele == '+' || ele == '-')
        return 1;
    else
        return -1;
}

bool ConvertEvaluate ::isoperand(char ele)
{
    return isalnum(ele);
}

bool ConvertEvaluate ::isoperator(char ele)
{
    if (inStackPriority(ele) == -1)
        return false;
    else
        return true;
}

void ConvertEvaluate ::printArray()
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        cout << postfix[i] << " ";
        i++;
    }
    cout << endl;
}

string ConvertEvaluate::postfixConversion(string infix)
{
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isoperand(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            stack_1.push_back(c);
        }
        else if (c == ')')
        {
            while (stack_1.top() != '(')
            {
                postfix += stack_1.top();
                stack_1.pop();
            }
            stack_1.pop();
        }
        else
        {
            while (!stack_1.isEmpty() && incomingPriority(c) <= inStackPriority(stack_1.top()))
            {
                postfix += stack_1.top();
                stack_1.pop();
            }
            stack_1.push_back(c);
        }
    }
    while (!stack_1.isEmpty())
    {
        postfix += stack_1.top();
        stack_1.pop();
    }
    return postfix;
}

string ConvertEvaluate::prefixConversion(string infix)
{
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    for (int i = 0; i < infix.length() / 2; i++)
    {
        swap(infix[i], infix[infix.length() - 1 - i]);
    }
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isoperand(c))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            stack_1.push_back(c);
        }
        else if (c == ')')
        {
            while (stack_1.top() != '(')
            {
                prefix += stack_1.top();
                stack_1.pop();
            }
            stack_1.pop();
        }
        else
        {
            while (!stack_1.isEmpty() && incomingPriority(c) < inStackPriority(stack_1.top()))
            {
                prefix += stack_1.top();
                stack_1.pop();
            }
            stack_1.push_back(c);
        }
    }
    while (!stack_1.isEmpty())
    {
        prefix += stack_1.top();
        stack_1.pop();
    }
    for (int i = 0; i < prefix.length() / 2; i++)
    {
        swap(prefix[i], prefix[prefix.length() - 1 - i]);
    }
    return prefix;
}

int ConvertEvaluate ::EvaluationPost()
{
    StackLL<char> stack_2;
    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (isalpha(c))
        {
            cout << "Enter value of operand " << c << " : " << endl;
            int num;
            cin >> num;
            c = num;
            arr[i].operand1 = c;
            arr[i].val1 = num;
            stack_2.push_back(c);
        }
        else if (isdigit(c))
        {
            stack_2.push_back(c);
        }
        else
        {
            char second = stack_2.pop();
            char first = stack_2.pop();
            int result;
            switch (c)
            {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
            case '^':
                result = pow(first, second);
                break;
            default:
                cout << "invalid " << endl;
                break;
            }
            stack_2.push_back(result);
        }
    }
    int ans = stack_2.pop();
    if (stack_2.isEmpty())
    {
        return ans;
    }
    else
    {
        cout << "invalid ans" << endl;
        return INT_MAX;
    }
}

int ConvertEvaluate ::EvaluationPre()
{
    StackLL<char> stack_3;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        if (isalpha(c))
        {
            cout << "Enter value of operand " << c << " : " << endl;
            int num;
            cin >> num;
            c = num;
            arr[i].operand1 = c;
            arr[i].val1 = num;
            stack_3.push_back(c);
        }
        else if (isdigit(c))
        {
            stack_3.push_back(c);
        }
        else
        {
            char first = stack_3.pop();
            char second = stack_3.pop();
            switch (c)
            {
            case '+':
                stack_3.push_back(first + second);
                break;
            case '-':
                stack_3.push_back(first - second);
                break;
            case '*':
                stack_3.push_back(first * second);
                break;
            case '/':
                stack_3.push_back(first / second);
                break;
            case '^':
                stack_3.push_back(pow(first, second));
                break;
            default:
                cout << "invalid " << endl;
                break;
            }
        }
    }
    int ans = stack_3.pop();
    if (stack_3.isEmpty())
    {
        return ans;
    }
    else
    {
        cout << "invalid ans" << endl;
        return INT_MAX;
    }
}

int main()
{
    bool flag = true;
    while (flag)
    {
        cout << "Enter the expression : ";
        string eqn;
        cin >> eqn;
        cout << "Enter your choice : " << endl;
        cout << "1 - Infix to postfix\n2 - Infix to prefix\n3 - postfix evaluation\n";
        cout << "4 - prefix evaluation\nPress 5 to exit." << endl;
        int choice;
        cin >> choice;
        string postfixE, prefixE;
        if (choice == 1)
        {
            ConvertEvaluate I;
            postfixE = I.postfixConversion(eqn);
            cout << "Postfix Expression : " << postfixE << endl;
            // int ans = I.EvaluationPost();
            // cout << "Result : " << ans << endl;
        }
        else if (choice == 2)
        {
            ConvertEvaluate I;
            prefixE = I.prefixConversion(eqn);
            cout << "Prefix Expression : " << prefixE << endl;
            // int ans = I.EvaluationPre();
            // cout << "Result : " << ans << endl;
        }
        else if (choice == 3)
        {
            ConvertEvaluate I;
            postfixE = I.postfixConversion(eqn);
            cout << "Postfix Expression : " << postfixE << endl;
            int ans = I.EvaluationPost();
            cout << "Result : " << ans << endl;
        }
        else if (choice == 4)
        {
            ConvertEvaluate I;
            prefixE = I.prefixConversion(eqn);
            cout << "Prefix Expression : " << prefixE << endl;
            int ans = I.EvaluationPre();
            cout << "Result : " << ans << endl;
        }
        else if (choice == 5)
        {
            exit(0);
        }
        cout << "Do you want to continue(y/n) : ";
        string temp;
        cin >> temp;
        if (temp == "n" || temp == "N")
            flag = false;
    }
    return 0;
}  
