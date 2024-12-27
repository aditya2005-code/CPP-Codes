#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {

public:
    Node* head;
    Node* tail;
    List() {
        head = NULL;
        tail = NULL;
    }

    void Push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void Push_back(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Push_position(int val, int pos) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            cout << "Linked list is empty. Adding the first node." << endl;
            head = tail = newNode;
            return;
        }
        if (pos == 1) {
            Push_front(val);
            return;
        }

        Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        // Case: Position out of bounds
        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }

        // Case: Insert at the end
        if (temp->next == NULL) {
            Push_back(val);
            return;
        }

        // Case: Insert in the middle
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Print_ll() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void Pop_front(){
        if( head == NULL){
            cout<<"Empty linked list" <<endl;
            return;
        }
        Node* temp = head ;
        head = head -> next ;
        temp -> next = NULL;
        free(temp);
    }

    void Pop_back(){
        if(head == NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }
        Node* temp = head ;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void Pop_position(int pos){
        if(head == NULL){
            cout<<"Empty linked list"<<endl;
            return;
        }

        if(pos == 1){
            cout<<"First node"<<endl;
            Pop_front();
            return;
        }
        Node* temp=head;
        Node* t1;
        int i=1;
        while( i < pos && temp != NULL ) {
            t1=temp;
            temp=temp->next;
            i++;
        }
        if(temp == NULL){
            cout<<"Position out of bound"<<endl;
            return;
        }
        if( temp->next == NULL){
            cout<<"Deleting last node"<<endl;
            Pop_back();
            return;
        }
        t1->next = temp->next;
        delete temp;
    }

    void search(int val){
        if(head == NULL){
            cout<<"Empty linked list "<<endl;
            return;
        }
        Node* temp = head;
        int i=0;
        while(temp->next != NULL){
            i++;
            if(temp->data == val){
                cout<<"DAta fount at pos "<<i;
                return;
            }
            temp = temp->next;
        }
        cout<<"Data not found"<<endl;
    }
    void recSearch(Node* temp,int val,int pos =1){
        if(temp == NULL){
            cout<<"Data not found"<<endl;
            return;
        }
        
        if(temp->data == val){
            cout<<"Data found at " << pos;
            return;
        }
        recSearch(temp->next,val,pos+1);
    }
    Node* getHead(){
        return head;
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        Node* Next= NULL;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev= curr;
            curr = Next;
        }
        tail = head; 
        head = prev;
    }

    ~List() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    List ll;
    ll.Push_front(20);
    ll.Push_front(30);
    ll.Push_front(40);
    ll.Push_back(50);
    ll.Push_back(60);

    ll.Print_ll(); // Expected output: 40->30->20->50->60->NULL

    ll.Push_position(25, 3); // Insert 25 at position 3
    ll.Print_ll(); // Expected output: 40->30->25->20->50->60->NULL

    ll.Push_position(100, 1); // Insert 100 at the front
    ll.Print_ll(); // Expected output: 100->40->30->25->20->50->60->NULL

    ll.Push_position(200, 10); // Position out of bounds
    ll.Pop_front();
    ll.Pop_back();
    ll.Print_ll();
    ll.Pop_position(2);
    ll.Print_ll();
    ll.search(25);
    ll.recSearch(ll.getHead(),25);
    ll.reverse();
    cout<<endl;
    ll.Print_ll();
    
    return 0;
}
