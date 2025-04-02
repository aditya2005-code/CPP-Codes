#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        cout<<s.top()<<" ";
        s.pop();
    }

}

int main(){
    queue<int> q;
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
 
    for(int i=0 ; i<n ; i++){
        q.push(i);
    }

    reverseQueue(q);
    
}