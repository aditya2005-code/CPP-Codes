#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
public:
    void Push(int val){
        if(s1.empty()){
            s1.push(val);
            return;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    void Pop(){
        if(s1.empty()){
            cout<<"Empty queue"<<endl;
            return;
        }
        s1.pop();
    }

    int Front(){
        return s1.top();
    }

    bool isEmpty(){
        return s1.empty();
    }
};

int main(){
    Queue q;
    q.Push(10);
    q.Push(20);
    q.Push(30);

    cout << "Front: " << q.Front() << endl; 

    q.Pop();
    cout << "Front after pop: " << q.Front() << endl; 

    q.Pop();
    
    q.Pop();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}