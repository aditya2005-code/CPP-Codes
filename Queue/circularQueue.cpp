#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Queue{
    int capacity;
    int* arr;
    int currentSize;
    int f ,r;
public:
    Queue(int capacity){
        this->capacity = capacity;
        currentSize = 0;
        f = r = -1;
        arr = new int[capacity];
    }
    
    void Push(int val){
        if(currentSize == capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
         if (f == -1) { 
            f = 0;
        }
        r = ( r+1 )% capacity;
        arr[r] = val;
        currentSize++;
    }

    void Pop(){
        if(currentSize == 0){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        f = ( f+1 ) % capacity;
        currentSize--;
        if (currentSize == 0) {  
            f = r = -1;
        }
    }

    int Front(){
        return arr[f];
    }

    int isEmpty(){
        return currentSize == 0;
    }
     ~Queue() {
        delete[] arr;  
    }

};

int main(){
    int n;
    cout << "Enter the value of n:" << endl;
    cin >> n;
    Queue q(n);
    q.Push(1);
    q.Push(2);
    q.Push(3);

    cout << "Front of the queue: " << q.Front() << endl;  
    q.Pop();
    cout << "Front after pop: " << q.Front() << endl;  
}