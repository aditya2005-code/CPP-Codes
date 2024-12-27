#include<iostream>
using namespace std;

void Upper(char str[], int n)
{
    for(int i=0; i<n ; i++){
        char ch=str[i];
        if( ch>='a' && ch<='z'){
            str[i]=ch-'a'+'A';
        }else{
            continue;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    cin.ignore();
    char str[n];
    cin.getline(str,n);

    Upper(str,n);
    
    cout<<"\n"<<str;
    return 0;
    
}