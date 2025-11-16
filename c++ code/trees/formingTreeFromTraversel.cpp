#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class TreeNode{
public:
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void createMap(vector<int>inorder,map<int,int>&inorderMap){
    for(int i =0;i<inorder.size();i++){
        inorderMap[inorder[i]]=i;
    }
}
int searchInInorder(vector<int>in,int ele){
    for(int i =0;i<in.size();i++){
        if(in[i]==ele)return i;
    }
    return -1;
}
void lvlordertraversel(TreeNode*root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front!=NULL){
            cout<<front->val<<" ";
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);
        }else{
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
    }
}
TreeNode* createTreeFromPreAndInordertraversel(vector<int>pre, vector<int>in,map<int,int>&inordermap,int &pindex, int is, int ie){
    if(pindex>=pre.size()||is>ie)return NULL;
    //ek case mei solve krunga
    TreeNode*newTreeNode=new TreeNode(pre[pindex]);
    //search the element in inorder
    // int pos=searchInInorder(in,pre[pindex]);// taking o(n) time to search therefore using map in second line to make it more efficient
    int pos=inordermap[pre[pindex]];
    pindex++;
    newTreeNode->left=createTreeFromPreAndInordertraversel(pre,in,inordermap,pindex,is,pos-1);
    newTreeNode->right=createTreeFromPreAndInordertraversel(pre,in,inordermap,pindex,pos+1,ie);
    return newTreeNode;
}

TreeNode* createTreeFromPostAndInordertraversel(vector<int>post, vector<int>in,map<int,int>&inordermap,int &postindex, int is, int ie){
    if(postindex<0||is>ie)return NULL;
    //ek case mei solve krunga
    TreeNode*newTreeNode=new TreeNode(post[postindex]);
    //search the element in inorder
    // int pos=searchInInorder(in,pre[pindex]);// taking o(n) time to search therefore using map in second line to make it more efficient
    int pos=inordermap[post[postindex]];
    postindex--;
    newTreeNode->right=createTreeFromPostAndInordertraversel(post,in,inordermap,postindex,pos+1,ie);
    newTreeNode->left=createTreeFromPostAndInordertraversel(post,in,inordermap,postindex,is,pos-1);
    return newTreeNode;
}

int main(){
    // preorder and inorder traversel is given return the formed tree
    vector<int>preorder={2,8,10,6,4,12};
    vector<int>inorder={10,8,6,2,4,12};
    int preorderIndex=0;
    int inorderStart=0;
    int inorderEnd=inorder.size()-1;
    map<int,int>inorderMap;// when finding preorder element in inorder vector it is taking o(n) time therefore using map to make it done in o(1) to make code more efficient ,this is second way .
    createMap(inorder, inorderMap); 
    TreeNode*root=createTreeFromPreAndInordertraversel(preorder, inorder,inorderMap, preorderIndex, inorderStart,inorderEnd);
    cout<<"printing the tree :"<<endl;
    lvlordertraversel(root);

    //post order and inrder traversel is givem form the tree
    vector<int>postorder={10,6,8,12,4,2};
    int postorderIndex=postorder.size()-1;
    //taking inorder, inorderStart , inorderEnd and inorder map from above code
    TreeNode*root2=createTreeFromPostAndInordertraversel(postorder, inorder,inorderMap, postorderIndex, inorderStart,inorderEnd);
    cout<<"printing the tree :"<<endl;
    lvlordertraversel(root2);
    return 0;
}