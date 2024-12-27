#include<iostream>
using namespace std;

int main()
{
    int x,y;
    cout<<"Enter the two numbers:";
    cin>>x>>y;

    if(x>y){
        cout<<x<<" Is greater"<<endl;
    }

    else if(y>x){
        cout<<y<<" Is greater"<<endl;
    }

    else{
        cout<<"X and Y are equal";
    }
    return 0;
}