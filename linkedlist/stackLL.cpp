#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<class T>
class Stack{
    list<T> ll;
    public:

    void push( T val){
        ll.push_front(val);
    }

    void pop(){
        if( ll.size() == 0){
            cout<<"Empty Stack"<<endl;
            return;
        }
        ll.pop_front();
    }

    T top(){
        return ll.front();
    }

    bool isEmpty(){
        return ll.size() == 0;
    }
};

int main(){
    Stack<int> s;
    s.pop();
    s.push(4);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    cout<<s.isEmpty()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}


