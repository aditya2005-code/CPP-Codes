#include<iostream>
using namespace std;

int main()
{
    int n,co=0;
   do{
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<endl;
    
    if(n%10==0){
        continue;
    }
    else{
        cout<<n<<endl;
    }
    co++;
   }while(1);

   return 0;
}