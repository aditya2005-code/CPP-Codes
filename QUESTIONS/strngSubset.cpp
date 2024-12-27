#include<iostream>
#include<string>
using namespace std;

void Subsets(string str , string substr)
{

    if(str.size() == 0){
        cout<<substr<<endl;
        return;
    }
    char ch=str[0];
    Subsets(str.substr(1,str.size()-1),substr+ch);
    Subsets(str.substr(1,str.size()-1),substr);    
}

int main()
{
    string str;
    getline(cin,str);
    Subsets(str,"");
    return 0;
}