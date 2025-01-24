#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    public:
    Node* head;
    Node* tail;

    Queue(){
        head = NULL;
        tail = NULL;
    }

    void Push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void Pop(){
        if( head == NULL ){
            cout<<"Underflow"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
        }
        cout<<temp->data;
        delete temp;
    }

    int Front(){
        if(head == NULL){
            cout<<"Empty Queue";
            return -1;
        }
        return head->data;
    }

    bool IsEmpty(){
        return head == NULL;
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
    cout << "Is queue empty? " << (q.IsEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
    
}