#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    //For traversal of ll
    void print_ll(){
        if(head == NULL){
            cout<<"Empty Linked List"<<endl;
            return;
        }
        Node* temp = head;
        while(temp  != NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    //push at front
    void push_front(int val){
        Node* newNode = new Node(val);
         if(head == NULL){
            head = tail = newNode;
            return;
         }
         newNode->next = head;
         head->prev = newNode;
         head = newNode;    
    }
    //push at back
    void push_back(int val){
        if(head == NULL){
            cout<<"Emmpty ll"<<endl;
            push_front(val);
            return;
        }
        Node* newNode = new Node(val);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }
    //Pop from front
    void pop_front(){
        if(head == NULL){
            cout<<"empty ll"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout<<temp->data<<"is deleted"<<endl;
        delete temp;
    }
    //Pop from back
    void pop_back(){
        if(head == NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }
        if(head->next == NULL){
            pop_front();
            return;
        }
        Node* temp = tail;
        temp->prev->next = NULL;
        tail = temp->prev;
        cout<<temp->data<<" is deleted"<<endl;
        delete temp;
        
    }
};

int main(){
    List ll;
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(20);
    ll.push_front(88);
    ll.print_ll();
    ll.push_back(65);
    ll.push_back(90);
    ll.print_ll();
    ll.pop_front();
    ll.pop_front();
    ll.print_ll();
    ll.pop_back();
    ll.pop_back();
    ll.print_ll();
}