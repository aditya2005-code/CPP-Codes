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

    // Print the circular linked list
    void print_ll() {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)" << endl;
    }

    // Push at the front
    void CircularPush_front(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
            tail->next = head;
            return;
        }
        temp->next = head;
        head = temp;
        tail->next = head;
    }

    // Push at the back
    void circularPush_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            CircularPush_front(val);
            return;
        }
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }

    // Push at a specific position
    void circularPush_pos(int val, int pos) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            cout << "Empty linked list. Adding as the first element." << endl;
            CircularPush_front(val);
            return;
        }
        if (pos == 1) {
            CircularPush_front(val);
            return;
        }
        Node* t1 = head;
        int i = 1;
        while (i < pos - 1 && t1->next != head) {
            t1 = t1->next;
            i++;
        }
        if (i < pos - 1) {
            cout << "Out of bound. Adding at the end." << endl;
            circularPush_back(val);
            return;
        }
        newNode->next = t1->next;
        t1->next = newNode;
        if (t1 == tail) {
            tail = newNode;
        }
    }

    // Pop from the front
    void Pop_front() {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    // Pop from the back
    void pop_back() {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }

    // Pop at a specific position
    void pop_pos(int pos) {
        if (head == NULL) {
            cout << "Empty linked list" << endl;
            return;
        }
        if (pos == 1) {
            Pop_front();
            return;
        }
        Node* t1 = head;
        int i = 1;
        while (i < pos - 1 && t1->next != head) {
            t1 = t1->next;
            i++;
        }
        if (t1->next == head || t1->next == tail->next) {
            cout << "Out of bound" << endl;
            return;
        }
        Node* toDelete = t1->next;
        t1->next = toDelete->next;
        if (toDelete == tail) {
            tail = t1;
        }
        delete toDelete;
    }
};

int main() {
    List ll;
    ll.CircularPush_front(20);
    ll.CircularPush_front(25);
    ll.CircularPush_front(30);
    ll.circularPush_back(10);
    ll.circularPush_pos(15, 2);
    ll.print_ll();
    ll.Pop_front();
    ll.print_ll();
    ll.pop_back();
    ll.print_ll();
    ll.pop_pos(2);
    ll.print_ll();
    return 0;
}
