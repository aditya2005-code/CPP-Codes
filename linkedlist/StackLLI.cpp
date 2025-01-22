#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node( T val){
        data = val;
        next = NULL;
    }
};

template<class T>
class Stack{
    Node<T>* head;
    public:
    Stack(){
        head = NULL;
    }
    void push( T val){
        Node<T>* newNode = new Node<T>(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop(){
        if( head == NULL){
            cout<<"Empty Stack"<<endl;
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        
    }

    T top(){
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
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


