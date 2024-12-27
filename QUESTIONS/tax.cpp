#include<iostream>
using namespace std;

int main(){
    int income;
    float tax;
    cout<<"Enter the income:";
    cin>>income;
    tax=0;
    if(income <500000){
        cout<<" 0 % tax "<<endl;
    }

    else if(income >= 500000 && income <= 1000000){
        cout<<"20% tax is applied"<<endl;
        tax= income/20;
    }
    else{
        cout<<"30% tax is applied"<<endl;
        tax=income/30;
    }
    cout<<"Tax is :"<<tax;
    return 0;
}