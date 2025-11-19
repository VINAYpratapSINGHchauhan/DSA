#include<iostream>
#include<queue>
#include<map>
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

void levelOrderTraverselWithMarker(node*root){ //this is with marker that each level element in each line
    // row wise traversel that is breadth first traversel
    cout<<"printing level order traversel :"<<endl;
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
void printLeftView(node*root, vector<int> &ans, int level){
    if(root==NULL){
        return ;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    printLeftView(root->left,ans,level+1);
    printLeftView(root->right,ans,level+1);
}
void printRightView(node*root, vector<int> &ans, int level){
    if(root==NULL){
        return ;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    printRightView(root->right,ans,level+1);
    printRightView(root->left,ans,level+1);
}
void leftViewByLevelTraversel(node*root){
    cout<<"Left view by level order traversel : "<<endl;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    //traversel
    bool flag=true;
    while(!q.empty()){
        //front ko print kro aur pop kro 
        node*front =q.front();
        q.pop();
        if(front==NULL){
            flag=true;
            if(!q.empty())
            q.push(NULL);
        }else{
            if(flag){
            cout<<front->data<<" ";
            flag=false;
            }
            //left aur right child dalo queue mei 
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);
        }
    }
}
void rightViewByLevelTraversel(node*root){
    cout<<"right view by level order traversel : "<<endl;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    //traversel
    bool flag=true;
    while(!q.empty()){
        //front ko print kro aur pop kro 
        node*front =q.front();
        q.pop();
        if(front==NULL){
            flag=true;
            if(!q.empty())
            q.push(NULL);
        }else{
            if(flag){
            cout<<front->data<<" ";
            flag=false;
            }
            //left aur right child dalo queue mei 
            if(front->right!=NULL)q.push(front->right);
            if(front->left!=NULL)q.push(front->left);
        }
    }
}
vector<int> printTopView(node*root){
    vector<int> ans ;
    if(root==NULL)return {};
    map <int ,int>leveltoNode;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*, int> fpair=q.front();
        q.pop();
        node*fnode=fpair.first;
        int level=fpair.second;
        if(leveltoNode.find(level)==leveltoNode.end()){
            leveltoNode[level]=fnode->data;
        }
        if(fnode->left!=NULL)q.push(make_pair(fnode->left,level-1));
        if(fnode->right!=NULL)q.push(make_pair(fnode->right,level+1));
    }
    for(auto v:leveltoNode){
        ans.push_back(v.second);
    }
    return ans;
}
vector<int> printBottomView(node*root){
    vector<int> ans ;
    if(root==NULL)return {};
    map <int ,int>leveltoNode;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*, int> fpair=q.front();
        q.pop();
        node*fnode=fpair.first;
        int level=fpair.second;
            leveltoNode[level]=fnode->data;
        if(fnode->left!=NULL)q.push(make_pair(fnode->left,level-1));
        if(fnode->right!=NULL)q.push(make_pair(fnode->right,level+1));
    }
    for(auto v:leveltoNode){
        ans.push_back(v.second);
    }
    return ans;
}
int main(){
    node*root=createTree();
    // tree is 10 30 61 -1 -1 60 62 -1 -1 -1 20 50 -1 65 -1 69 -1 -1 40 -1 -1 
    levelOrderTraverselWithMarker(root);
    vector<int>leftView;
    printLeftView(root,leftView,0);
    cout<<endl;
    cout<<"printing left view of the tree :"<<endl;
    for (int  i = 0; i < leftView.size(); i++)
    {
        cout<<leftView[i]<<" ";
    }
    vector<int>rightView;
    printRightView(root,rightView,0);
    cout<<endl;
    cout<<"printing right view of the tree :"<<endl;
    for (int  i = 0; i < rightView.size(); i++)
    {
        cout<<rightView[i]<<" ";
    }
    cout<<endl;
    // solving left and right view question by level order traversel solution approach
    leftViewByLevelTraversel(root);
    cout<<endl;
    rightViewByLevelTraversel(root);
    cout<<endl;
    vector<int> topview=printTopView(root);
    vector<int> bottomview=printBottomView(root);
    cout<<"printing top view : "<<endl;
    for(auto e:topview){
        cout<<e<<" ";
    }
    cout<<endl;
    cout<<"printing bottom view : "<<endl;
    for(auto e:bottomview){
        cout<<e<<" ";
    }
    
    return 0;
}