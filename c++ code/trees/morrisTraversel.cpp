#include<iostream>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
TreeNode*createTree(){
    int data;
    cout<<" enter the value of node : ";
    cin>>data;
    if(data==-1)return NULL;
    TreeNode*root=new TreeNode(data);
    cout<<"for the left node of "<<root->data;
    root->left=createTree();
    cout<<"for the right node of "<<root->data;
    root->right=createTree();
    return root;
}
void inorderMorrisTraversel(TreeNode*root){
    TreeNode*curr=root;
    while(curr){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{
            TreeNode*prev=curr->left;
            while(prev->right &&prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
    cout <<endl;
}
void preorderMorrisTraversel(TreeNode*root){
    TreeNode*curr=root;
    while(curr){
        if(!curr->left){
            cout<<curr->data<<" ";
            curr=curr->right;
        }else{
            TreeNode*prev=curr->left;
            while(prev->right &&prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                cout<<curr->data<<" ";
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    cout <<endl;
}
int main(){
    //tree
    TreeNode* root=createTree();
    //morris Traversel - it is a traversel that takes O(1) space complexity fro the traverse;

    // 1. inorder traversel of treee through morris traversing 
    cout <<"\nprinting the inorder traversel of the tree through morris : \n";
    inorderMorrisTraversel(root);
    // 2. preorder traversel of treee through morris traversing 
    cout <<"\nprinting the preorder traversel of the tree through morris : \n";
    preorderMorrisTraversel(root);

    return 0;
}