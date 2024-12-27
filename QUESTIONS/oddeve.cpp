#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;

    if(n%2==0){
        cout<<n<<" is a even number"<<endl;
    }
    else{
        cout<<n<<" Is a odd number";
    }
    return 0;
}