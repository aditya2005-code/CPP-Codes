#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

void firstNonRepeatingChar(string str){
    vector<int> freq(26,0);
    queue<char> q;

    for(int i= 0 ; i<str.length() ; i++){
        char ch = str[i];
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty() && freq[q.front()-'a'] > 1){
            q.pop();
        }
        if(q.empty()){
            cout<<"-1"<<" ";
        } else {
            cout<<q.front()<<" ";
        }
    }
}

int main(){
    string str;
    cout<<"Enter the String :";
    getline(cin,str);

    firstNonRepeatingChar(str);
    return 0;    
}