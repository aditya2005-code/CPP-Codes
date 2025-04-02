#include<iostream>
using namespace std;

void isPrint(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" ";
    isPrint(n-1);

}
void isPrintIncreasing(int n){
    if(n == 0){
        return;
    }
    isPrintIncreasing(n-1);
    cout<<n<<" ";
    
}

int main(){
    int n ;
    cout<<"Enter the valur of n:";
    cin>>n;

    isPrint(n);
    cout<<endl;
    isPrintIncreasing(n);

    return 0;
}