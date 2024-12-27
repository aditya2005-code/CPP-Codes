#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of subject:";
    cin>>n;
    int arr[n];
    int sum=0;
    cout<<"Enter the marks:";
    for(int i=0 ; i<n ; i++){
         
        cin>>arr[i];
        sum+=arr[i];
    }
    float avg=sum/2;

    cout<<"The average is:"<<avg<<endl;

    return 0;

}