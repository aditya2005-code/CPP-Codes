#include<iostream>
#include<string>
using namespace std;

bool checkString(string str1, string str2){
    int count=0;
    int k=0;
    int idx[k];
    for(int i=0; i<str1.length() ; i++){
        if(str1[i]!=str2[i]){
            count++;
            idx[k]=i;
            k++;
        }
    }
    
    if(count>2){
        return false;
    }
    char temp=str2[idx[0]];
    str2[idx[0]]=str2[idx[1]];
    str2[idx[1]]=temp;
    cout<<str2;

    return true;
}

int main()
{
    string str1,str2;
    cout<<"Enter the first string:";
    getline(cin,str1);
    cout<<"\nEnter the second string: ";
    getline(cin,str2);
    bool res=checkString(str1,str2);

    if(res==true){
        cout<<"Possible";
    }

    else{
        cout<<"not possible";
    }
    return 0;

}