#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Queue{
    public:
    vector<int> data;
    vector<int> prt;
    int front = 0;
    
    void push(int val, int p) {
        int n = data.size();
        int pos = n; 
        
        for (int i = 0; i < n; i++) {
            if (prt[i] < p) {
                pos = i;
                break;
            }
        }
        
        data.insert(data.begin() + pos, val);
        prt.insert(prt.begin() + pos, p);
    }

    void pop(){
        if(front == data.size()){
            cout<<"Out of bound"<<endl;
            return;
        }
        int d = data[front];
        
        front++;
        cout<<d<<endl;
    }

    void Print(){
        for(int i=0 ; i<data.size() ; i++){
            cout<<data[i]<<" ";
        } 
        cout<<endl;
    }

};

int main(){
    Queue q;
    q.push(3,6);
    
    q.push(4,7);
    
    q.push(5,5);
    q.Print();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    return 0;
}

