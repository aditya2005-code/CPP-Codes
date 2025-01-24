// C++ Program to illustrate how we can reverse a stack
#include <iostream>
#include <stack>
using namespace std;

// utility function to print stack
void printStack(stack<int> st)
{
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    // Initialize a stack
    stack<int> currentStack;

    // Push some elements into the stack
    currentStack.push(1);
    currentStack.push(2);
    currentStack.push(3);
    currentStack.push(4);
    currentStack.push(5);

    // Print the original stack
    cout << "Original stack: ";
    printStack(currentStack);

    // Reverse the stack
    stack<int> tempStack;
    while (!currentStack.empty()) {
        tempStack.push(currentStack.top());
        currentStack.pop();
    }
    currentStack = tempStack;

    // Print the reversed stack
    cout << "Reversed stack: ";
    printStack(currentStack);

    return 0;
}
