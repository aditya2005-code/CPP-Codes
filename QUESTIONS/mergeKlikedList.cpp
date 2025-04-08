#include <iostream>
#include<vector>
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
        if (temp == NULL) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }

      
        if (temp->next == NULL) {
            Push_back(val);
            return;
        }

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

    Node* mergeKLists(vector<Node*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
       
        Node* dummy = NULL;
        int j = 0;
        while(!dummy){
            if(j >= n) return NULL;
            dummy = lists[j];
            j++;
        }

        for (int i = j; i < lists.size(); i++) {
            Node* list1 = dummy;
            Node* list2 = lists[i];

            if (!list2) continue;

            Node* head = NULL;
            Node* tail = NULL;

           
            if (list1->data <= list2->data) {
                head = tail = list1;
                list1 = list1->next;
            } else {
                head = tail = list2;
                list2 = list2->next;
            }

            
            while (list1 && list2) {
                if (list1->data <= list2->data) {
                    tail->next = list1;
                    tail = list1;
                    list1 = list1->next;
                } else {
                    tail->next = list2;
                    tail = list2;
                    list2 = list2->next;
                }
            }

            
            while (list1) {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }

            while (list2) {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }

            dummy = head;
        }

        return dummy;
    }
    
};



int main() {
    List ll;
    ll.Push_front(20);
    ll.Push_front(30);
    ll.Push_front(40);
    ll.Push_back(50);
    ll.Push_back(60);

   
    
    return 0;
}
