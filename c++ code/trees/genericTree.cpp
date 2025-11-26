#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data ;
    int childCount;
    TreeNode**children;
    TreeNode(int val, int childCount){
        this->data=val;
        this->childCount=childCount;
        this->children=new TreeNode*[childCount];
    }
};
TreeNode* createTree(){
    int data,count=0;
    cout<<" enter the data for the node : "<<endl;
    cin>>data;
    cout<<"enter the number of children for the node "<<data<<" : \n";
    cin>>count;
    TreeNode*root=new TreeNode(data,count);
    for(int i =0;i<root->childCount;i++){
        cout<<"for the "<<i+1<<" node of "<<root->data;
        root->children[i]=createTree();
    }
    return root;
}
void levelOrderTraversel(TreeNode*root){
    if(!root)return ;
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode*front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }else{
            cout<<front->data<<" ";
            for(int i =0;i<front->childCount;i++){
                if(front->children[i])q.push(front->children[i]);
            }
        }
    }
}
int main(){
    TreeNode*root=createTree();
    cout<<"Printing the Generic Tree : \n";
    levelOrderTraversel(root);
    return 0;
}