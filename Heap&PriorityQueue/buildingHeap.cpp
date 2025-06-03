#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Heap
{
public:
    vector<int> heap;

    
    void heapify(int parent, int leftchild, int rightchild) {
        int largest = parent;

        if (leftchild < heap.size() && heap[leftchild] > heap[largest])
            largest = leftchild;

        if (rightchild < heap.size() && heap[rightchild] > heap[largest])
            largest = rightchild;

        if (largest != parent) {
            swap(heap[parent], heap[largest]);
            heapify(largest, 2 * largest + 1, 2 * largest + 2);
        }
    }

    void pushHeap(int val)
    {
        if (heap.size() == 0)
        {
            heap.push_back(val);
            return;
        }
        heap.push_back(val);
        int child = heap.size() - 1;
        int parent = (child - 1) / 2;
        while (parent >= 0 && heap[parent] < heap[child])
        {
            swap(heap[parent], heap[child]);
            child = parent;
            parent = (child-1)/2;
        }
    }

    void popHeap(){
        if(heap.size() == 1){
            heap.pop_back();
            return;
        }

        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0, 1,2);
    }

    void printHeap(){
        for(int i=0 ; i<heap.size() ; i++){
            cout<<heap[i] << " ";
        }
    }
};

int main(){
    Heap h1;
    h1.pushHeap(1);
    h1.pushHeap(2);
    h1.pushHeap(3);
    h1.pushHeap(4);
    h1.pushHeap(5);
    h1.pushHeap(9);
    h1.pushHeap(10);
    h1.printHeap();
    h1.popHeap();
    cout << endl;
    h1.printHeap();
    h1.popHeap();
    cout<<endl;
    h1.printHeap();
    return 0;
}