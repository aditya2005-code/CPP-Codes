#include<iostream>
using namespace std;

char ch(char word)
{
    if(word=='z'){
        return 'a';
    }
    else{
        return word+1;
    }
}

int main(){
    char word;
    cout<<"Enter the alphabet:";
    cin>>word;

    char res= ch(word);
    cout<<res;
    return 0;

}