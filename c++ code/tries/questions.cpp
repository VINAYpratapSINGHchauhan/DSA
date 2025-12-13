#include<iostream>
#include<vector>
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
void storeWords(TrieNode*root,vector<string>&ans,string &word){
    //base case
    if(root->isTerminal){
        ans.push_back(word);
    }
    for(int i =0;i<26;i++){
        TrieNode*child=root->children[i];
        if(child){
            word.push_back(child->val);
            storeWords(child,ans,word);
            word.pop_back();
        }
    }
}
void countWords(TrieNode*root,string prefix,vector<string>&ans,int i){
    //base case
    if(i==prefix.length()){
        // if(root->isTerminal)ans.push_back(prefix);
        storeWords(root,ans,prefix);
        cout<<"successully founded words\n";
        return ;
    }
    int index=prefix[i]-'a';
    if(index<0||index>=26||!root->children[index]){
        cout<<"invalid prefix\n";
        return ;
    }
    countWords(root->children[index],prefix,ans,i+1);
}
int main(){
    //creation
    TrieNode* root=new TrieNode('-');
    //insertion
    insertTrie(root,"vinay");
    insertTrie(root,"vin");
    insertTrie(root,"vinayak");
    insertTrie(root,"vinu");
    insertTrie(root,"pratap");
    insertTrie(root,"singh");
    insertTrie(root,"chauhan");
    // printng the words that starts with the specific prefix
    string prefix="viny";
    vector<string> words;
    countWords(root,prefix,words,0);
    for(auto str:words)cout<<str<<" ";
    return 0;
}