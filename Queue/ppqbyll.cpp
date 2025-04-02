#include<bits/stdc++.h>

class Node{
    public:
    int data;
    int priority;
    Node* next;

    Node(int val , int prt){
        data = val;
        priority = prt;
        next = NULL;
    }

};