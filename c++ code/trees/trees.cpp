#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
node* createTree(){
    int val;
    cout<<"enter the value of node"<<endl;
    cin>>val;
    //base case
    if(val==-1){
        return NULL;
    }
    //hm ek case solve krenge that is we make the root node and rest will be done by recursion
    //hm root node bnayenge
    node* root=new node(val);
    //RECURSION
    //left subtree
    cout<<"for left node of "<<root->data<<endl;
    root->left=createTree();
    //right subtree
    cout<<"for right node of "<<root->data<<endl;
    root->right=createTree();
    return root;
}

void preOrderTraversel(node* root){
    //base case
    if(root==NULL){
        return;
    }
    // pre order traversel  NLR
    // 1. N - current node
    cout<<root->data<<" ";
    // 2. L - left node
    preOrderTraversel(root->left);
    // 3. R - right part
    preOrderTraversel(root->right);
}
void inOrderTraversel(node* root){
    //base case
    if(root==NULL){
        return ;
    }
    // inOrder - LNR
    // 1. L- left part
    inOrderTraversel(root->left);
    // 2. N- cuurent node
    cout<<root->data<<" ";
    // 3. R- right part
    inOrderTraversel(root->right);
}
void postOrderTraversel(node* root){
    //base case
    if(root==NULL){
        return ;
    }
    // postOrder - LRN
    // 1. L- left part
    postOrderTraversel(root->left);
    // 2. R- right part
    postOrderTraversel(root->right);
    // 3. N- cuurent node
    cout<<root->data<<" ";
}
int main(){
    node* root=createTree();
    cout<<"Pre Order Traversel of the Tree is "<<endl;
    preOrderTraversel(root);
    cout<<endl;
    cout<<"IN Order Traversel of the Tree is "<<endl;
    inOrderTraversel(root);
    cout<<endl;
    cout<<"Post Order Traversel of the Tree is "<<endl;
    postOrderTraversel(root);
    return 0;
}