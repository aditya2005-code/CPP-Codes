#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

void interLeave2Queues(queue<int> q1){
    queue<int> q2;
    int n = q1.size();
    int mid = n/2;
    for(int i=0 ; i<mid ; i++){
        q2.push(q1.front());
        q1.pop();
    }

    for(int i=0 ; i<n/2 ; i++){
        q1.push(q2.front());
        q2.pop();
        q1.push(q1.front());
        q1.pop();
    }

    for(int i=0 ; i<n ; i++){
        cout<<q1.front()<<" ";
        q1.pop();
    }
}

int main(){
    queue<int> q;
    int n;
    for(int i=0 ; i<10 ; i++){
        cin>>n;
        q.push(n);
    }
    interLeave2Queues(q);
    return 0;
}