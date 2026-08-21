#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int num = s1.top();
            s1.pop();
            s2.push(num);
        }

        s2.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int num = s1.top();
        s1.pop();

        return num;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){
    MyQueue mq;

    mq.push(1);
    mq.push(2);
    mq.push(3);
    mq.push(4);

    cout<<mq.pop()<<endl;
    cout<<mq.peek()<<endl;
    cout<<mq.empty()<<endl;

    return 0;

}