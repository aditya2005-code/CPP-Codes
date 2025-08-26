#include<iostream>
#include<unordered_map>
using namespace std;

string removeDuplicate(string str , string res , int i , unordered_map<char,int> freq){
    if( i == str.size()){
        return res;
    }

    if(freq[str[i]] == 0){
        res+=str[i];
        freq[str[i]]++;
    }

    return removeDuplicate(str,res,i+1,freq);
}

int main(){
    string str;
    cin >> str;
    unordered_map<char,int> freq;
    string res = removeDuplicate(str, "" , 0 , freq);
    cout<<res;
    return 0;
}