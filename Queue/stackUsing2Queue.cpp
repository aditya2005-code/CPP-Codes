#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    
    void Push(int val){
        if(q1.empty()){
            q1.push(val);
            return;
        }

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(val);
        
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

     void Pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        q1.pop();
    }

    int front() {
        if (q1.empty()) {
            cout << "Stack is empty. Returning -1 as a placeholder.\n";
            return -1;
        }
        return q1.front();
    }


    bool isEmpty(){
        return q1.empty();
    }

};

int main(){
     Stack st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    cout << "Top element: " << st.front() << endl; // Output: 30

    st.Pop();
    cout << "Top element after one pop: " << st.front() << endl; // Output: 20

    st.Pop();
    st.Pop();

    st.Pop(); 
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}