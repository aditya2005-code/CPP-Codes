#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    cout<<endl<<"Logic of pattern"<<endl;
    int k=n;

    for(int i=0; i<=2*n ; i++){
        for(int j=0 ; j<=2*n ; j++){
            if(i<=n){
                if(j<n-i || j>n+i){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            else{
                if(j<i-n || j>3*n-i){
                    cout<<" ";
                }
                else{
                    cout<<"*";
                }
            }
            
            }
            cout<<endl;
            
        }
        return 0;
        
    }

  