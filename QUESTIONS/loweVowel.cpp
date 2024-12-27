#include<iostream>
#include<string>
using namespace std;

void VowelCount( string str )
{
    int count=0;
    string vowel="aeiou";
    for(int i=0; i<str.length() ; i++){
        for(int j=0; j<str.length(); j++){
           if(str[i]==vowel[j]){
            count++;
            break;
            }
        }
    }   
    cout<<endl<<count;
}

int main()
{
    string  word;
    cout<<"Entr the string:";
    getline(cin,word);

    VowelCount(word);
    return 0;
}