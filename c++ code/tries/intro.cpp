#include<iostream>
using namespace std;
//structure of the trie node
class TrieNode{
    public:
    char val;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char ch){
        this->val=ch;
        this->isTerminal=false;
        for(int i =0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};
void insertTrie(TrieNode*root,string s ){
    if(s.length()==0){
        cout<<"insertion successfully\n";
        root->isTerminal=true;
        return ;
    }else{
        char ch=s[0];
        int index=ch-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            //present
            child =root->children[index];
        }else{
            //absent
            child =new TrieNode(ch);
            root->children[index]=child;
        }
        insertTrie(child,s.substr(1));
    }
}
bool searchTrie(TrieNode*root,string s,int i ){
    if (i == s.length())
        return root->isTerminal;
    int index = s[i] - 'a';
    if (index < 0 || index >= 26) return false;
    if (root->children[index] == NULL)
        return false;
    return searchTrie(root->children[index], s, i+1);
}
void deleteTrie(TrieNode*root,string s,int i ){
    if(i==s.length()){
        if(root->isTerminal){
        root->isTerminal=false;
        cout<<"deleted sucessfully"<<endl;
        return ;
        }else{
            cout<<"invalid deletion\n";
            return;
        }
    }
    int index=s[i]-'a';
    if(index<0||index>=26||root->children[index]==NULL){
        cout<<"invalid deletion\n";
        return;
    }
    deleteTrie(root->children[index],s,i+1);
    
}
void printTrie(TrieNode*root){

}
int main(){
    //creation
    TrieNode* root=new TrieNode('-');
    //insertion
    insertTrie(root,"vinay");
    insertTrie(root,"pratap");
    insertTrie(root,"singh");
    insertTrie(root,"chauhan");
    //searching
    if(searchTrie(root,"vinay",0))cout<<"present\n";
    else cout<<"absent\n";
    //deletion
    deleteTrie(root,"vinay",0);
    if(searchTrie(root,"vinay",0))cout<<"present\n";
    else cout<<"absent\n";
    return 0;
}