#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    unordered_map<char,Node*> child;
    bool end;
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
    }

    void insert(string word){
        Node* temp = root;

        for(int i=0 ; i<word.size() ; i++){

            if(temp->child.count(word[i]) == 0){
                temp->child[word[i]] = new Node();
            }
            temp = temp->child[word[i]];

        }
        temp->end = true;
    }

    bool search(string word){
        Node* temp = root;

        for(int i=0;i < word.size() ; i++){
            if(temp->child[word[i]] == NULL){
                return false;
            }
            temp = temp->child[word[i]];
        }
        return temp->end;
    }
};

int main(){
    Trie* trie = new Trie();
    string word = "hello";
    trie->insert(word);
    trie->insert("hell");
    trie->insert("mango");
    trie->insert("manly");

    cout << trie->search(word) << endl;
    cout << trie->search("mangos") << endl;
    return 0;
}