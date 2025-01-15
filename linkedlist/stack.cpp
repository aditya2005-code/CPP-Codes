#include<iostream> 
#include<vector>
using namespace std;

class Stack{
    vector<char> vec;
    public:

    void displayStack(){
        while(!isEmpty()){
            cout<<top();
            pop();
        }
    }

    void push(char val){
        vec.push_back(val);
    }
    void pop(){
        if(isEmpty()){
            cout<<"underflow"<<endl;
            return;
        }
        vec.pop_back();
    }
    char top(){
        return vec[vec.size()-1];
    }
    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main(){
    Stack s;
    s.push('a');
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

}