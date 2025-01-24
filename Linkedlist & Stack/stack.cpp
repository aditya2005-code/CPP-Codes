#include<iostream> 
#include<vector>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;
    public:

    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
            return;
        }
        vec.pop_back();
    }
    T top(){
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        int idx = vec.size()-1;

        return vec[idx];
    }

    bool isEmpty(){
        return vec.size() == 0;
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