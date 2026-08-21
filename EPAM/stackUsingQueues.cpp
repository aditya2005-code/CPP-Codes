#include<bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int> q1;
    queue<int> q2;
    int t = -1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        t = x;
    }
    
    int pop() {
        if(q1.empty()){
            return -1;
        }
        int n = q1.size() , i = 0;
        int p = 0;

        while(i < n-1){
            int x = q1.front();
            q1.pop();
            q2.push(x);
            i++;
        }
        cout<<endl;
        p = q1.front();
        q1.pop();

        while(!q2.empty()){
            int x = q2.front();
            q2.pop();
            t = x;
            q1.push(x);
        }

        return p;

    }
    
    int top() {
        if(q1.empty()){
            return -1;
        }
        return t;
    }
    
    bool empty() {
        return q1.empty();
    }
};


int main(){
    MyStack ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    cout<<"Popped : " << ms.pop()<<endl;
    cout<<"TOP : " <<ms.top()<<endl;
    cout<<ms.empty();

    return 0;
}