#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int>& s , int value){
    
    if(s.empty()){
        s.push(value);
        return;
    }
    int temp=s.top();
    s.pop();
    pushAtBottom(s,value);
    s.push(temp);
    
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    int n;
    cin>>n;
    pushAtBottom(s,n);
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}