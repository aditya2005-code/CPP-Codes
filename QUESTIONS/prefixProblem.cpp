#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*> child;
    bool end;
    int freq;
    Node(){
        end = false;
    }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
        root->end = false;
        root->freq = 0;
    }

    void insert(string word){
        Node* temp = root;

        for(int i=0 ; i<word.size() ; i++){
            if(temp->child.count(word[i]) == 0){
                temp->child[word[i]] = new Node();
                temp->child[word[i]]->freq = 1;
            }
            else{
                temp->child[word[i]]->freq++;
            }
            temp = temp->child[word[i]];
        }
        temp->end = true;
    }

    string prefix(string word){
        Node* temp = root;
        string res = "";

        for(int i = 0 ; i<word.size() ; i++){
            res += word[i];
            if(temp->child[word[i]]->freq == 1 || temp->end == true){
                return res;
            }
            temp = temp->child[word[i]];
        }
        return res;
    }
};

vector<string> specialPrefix(vector<string> words){
    if(words.size() == 0){
        return {};
    }

    vector<string> res;

    Trie* tree = new Trie();

    for(int i=0 ; i<words.size() ; i++){
        tree->insert(words[i]);
    }
    
    for(int i=0 ; i<words.size() ; i++){
        res.push_back(tree->prefix(words[i]));
    }

    return res;
}

int main(){
    vector<string> words;

    int n ;
    cout << "Ennter the ssize of the array:";
    cin >> n;
    words.resize(n);
    for(int i=0 ; i<n ; i++){
        cin>> words[i] ;
    }

    vector<string> res = specialPrefix(words);

    for(int i=0 ; i<res.size() ; i++){
        cout<<res[i] << " ";
    }
    return 0;
}