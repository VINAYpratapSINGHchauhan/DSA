#include<iostream>
#include<queue>
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
void levelOrderTraversel(node*root){ //this is without marker that is here all node are in one line
    // row wise traversel that is breadth first traversel
    queue<node*>q;
    q.push(root);
    //traversel
    while(!q.empty()){
        //front ko print kro aur pop kro 
        node*front =q.front();
        q.pop();
        cout<<front->data<<" ";
        //left aur right child dalo queue mei 
        if(front->left!=NULL)q.push(front->left);
        if(front->right!=NULL)q.push(front->right);
    }
}
void levelOrderTraverselWithMarker(node*root){ //this is with marker that each level element in each line
    // row wise traversel that is breadth first traversel
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    //traversel
    while(!q.empty()&&q.size()>1){
        //front ko print kro aur pop kro 
        node*front =q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            q.push(NULL);
        }else{
            cout<<front->data<<" ";
            //left aur right child dalo queue mei 
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);
        }
    }
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
    cout<<endl;
    cout<<"level Order Traversel of the Tree is "<<endl;
    levelOrderTraversel(root);
    cout<<endl;
    cout<<"level Order Traversel with marker of the Tree is "<<endl;
    levelOrderTraverselWithMarker(root);
    return 0;
}