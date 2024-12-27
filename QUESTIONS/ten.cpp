#include<iostream>
using namespace std;

int main(){
    int n;
    while(1){
        cout<<"Enter the value of n:"<<endl;
        cin>>n;
        if(n%10==0){
            break;
        }
        else{
            cout<<n<<"\t";
        }
    }
    return 0;
}