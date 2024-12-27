#include<iostream>
#include<string>
using namespace std;

void permutation(string str , string ans){
    if(str.size() == 0){
        cout<<ans<<endl;
        return;
    }
    int n=str.size();
    for(int i=0 ; i< str.size() ; i++){
        char c= str[i];
        string next = str.substr(0,i)+str.substr(i+1,n-i-1);
        permutation(next,ans+c);
    }

}

int main(){
    string str;
    getline(cin,str);
    permutation(str,"");
    return 0;
}