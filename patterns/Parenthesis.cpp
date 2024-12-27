#include<iostream>
using namespace std;

bool parenthesis(string str)
{
    int p[]={'(',')','{','}','[',']'};
    int* freq= (int*)malloc(sizeof(int)),k=0;
    freq={0};
    for(int i=0 ; i<str.length() ; i++){
      for(int j=0; j<i<str.length() ; j++){
        if(p[i]==str[j]){
            freq[i]++;
            k++;
        }
      }
    }
   for(int i=0; i<k ; i++){
    cout<<endl<<freq[i]<<" ";
   }
    return true;
}

int main()
{
    string str;
    cout<<"Enter the strings:";
    getline(cin,str);
    
}