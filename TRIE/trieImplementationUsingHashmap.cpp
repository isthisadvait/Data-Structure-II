/*Implementing Trie data Structure Using Hashmap
                   Implemented By : Raman Mehta
 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    bool isTerminal;
    unordered_map<char,Node*>child;
    Node(char ch){
        this->data=ch;
        this->isTerminal=false;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        this->root=new Node('\0');
    }
    
    void insert(string str){
        Node *temp=this->root;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp->child.count(ch)){
                temp=temp->child[ch];
            }else{
                Node *n=new Node(ch);
                temp->child[ch]=n;
                temp=n;
            }
        }
        temp->isTerminal=true;
        return;
    }
    bool search(string str){
        Node *temp=this->root;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp->child.count(ch)){
                temp=temp->child[ch];
            }else{
                return false;
            }
        }
        
        return  (temp->isTerminal==true);
    }
    void helperDFS(Node *root,string str,string op){
        if(root==NULL){
            return;
        }
        if(root->isTerminal){
            cout<<(str+op)<<"\n";
        }
        for(auto ch:root->child){
            helperDFS(ch.second,str,op+ch.first);
        }
    }
    void printPrefix(string str){
        Node *temp=this->root;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(temp->child.count(ch)){
                temp=temp->child[ch];
            }else{
                cout<<"No Such Prefix is there";
                return ;
            }
        }
        helperDFS(temp,str,"");
    }
};

int main(){
    string str;
    int t;
    cin>>t;
    Trie tr;
    while (t--)
    {
        /* code */
        cin>>str;
        tr.insert(str);
    }
    int q; cin>>q;
    while(q--){
        cin>>str;
        cout<<(tr.search(str))<<" ";
    }
    cout<<endl;
    int pref;
    cin>>pref;
    while(pref--){
        cin>>str;
        tr.printPrefix(str);
        cout<<endl;
    }
}
