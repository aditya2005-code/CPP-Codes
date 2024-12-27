#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int arr[n][n];
    
        for(int i=0 ; i<n ; i++){
          for(int j=0; j<n ; j++){
            cout<<"Enter the value of arr "<<"["<<i<<"]"<<"["<<j<<"] :";
            cin>>arr[i][j];
        }
    }

    int flag=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0; j<n ; j++){
            if(arr[i][j]==7){
                flag++;
            }
        }
    }
    if(flag==0){
        cout<<"Occurence is 0";

    }
    else{
        cout<<"The occurence of 7 is "<<flag;
    }
    return 0;
}