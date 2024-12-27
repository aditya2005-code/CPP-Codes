#include<iostream>
using namespace std;

int palindrome(int n)
{
    if(n==0 || n==1){
        return 1;
    }

    int rem,res=0;
    while(n!=0){
        rem=n%10;
        res=res*10+rem;
        n/=10;
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the number :";
    cin>>n;

    int result=palindrome(n);

    if(result==n){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome:";
    }
    return 0;
}