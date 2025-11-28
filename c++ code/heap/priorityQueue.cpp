#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
TreeNode* createTree(){
    int val;
    cout<<"enter the value of node"<<endl;
    cin>>val;
    //base case
    if(val==-1){
        return NULL;
    }
    //hm ek case solve krenge that is we make the root node and rest will be done by recursion
    //hm root node bnayenge
    TreeNode* root=new TreeNode(val);
    //RECURSION
    //left subtree
    cout<<"for left node of "<<root->data<<endl;
    root->left=createTree();
    //right subtree
    cout<<"for right node of "<<root->data<<endl;
    root->right=createTree();
    return root;
}
int kthlargestEle(vector<int>arr, int k ){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i =0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        if(pq.top()<arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
bool checkHeap(TreeNode* root) {
    if(root == NULL) return true;
    // If leaf node → OK
    if(root->left == NULL && root->right == NULL) return true;
    // If only left child exists
    if(root->right == NULL) {
        return root->data >= root->left->data && checkHeap(root->left);
    }
    // If both children exist
    bool leftOK = root->data >= root->left->data;
    bool rightOK = root->data >= root->right->data;
    return leftOK && rightOK && checkHeap(root->left) && checkHeap(root->right);
}
bool checkCBT(TreeNode*root){
    queue<TreeNode*>q;
    q.push(root);
    bool nullfound=false;
    while(!q.empty()){
        TreeNode*front=q.front();
        q.pop();
        if(front==NULL)nullfound=true;
        else{
            if(nullfound)return false;
            q.push(front->left);
            q.push(front->right);
        }
    }
    return true;
}
int main(){
    //creating a max heap 
    priority_queue<int>pq;
    pq.push(10);
    pq.push(12);
    pq.push(13);
    pq.push(16);
    pq.push(1);
    pq.push(100);
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
    cout<<"top element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"top element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"top element : "<<pq.top()<<endl;

    //creating the min heap 
    priority_queue<int,vector<int>,greater<int>>pq2;
    pq2.push(10);
    pq2.push(12);
    pq2.push(13);
    pq2.push(16);
    pq2.push(1);
    pq2.push(100);
    cout<<pq2.size()<<endl;
    cout<<pq2.empty()<<endl;
    cout<<"top element : "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"top element : "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"top element : "<<pq2.top()<<endl;

    //find the k th largest element in the array without sorting
    vector<int> arr={12,34,21,22,11,56,78};
    int k =6;
    cout<<"k th largest element is : "<<kthlargestEle(arr,k)<<endl;

    //check that a given complete binary tree is a valid heap or not
    //this is complete binary treee
    TreeNode*root=createTree();
    cout<<"Is CBT a valid heap : \n";
    checkHeap(root)?cout<<"true":cout<<"false"<<endl;

    //check if a tree is complete binary tree or not
    TreeNode*root2=createTree();
    cout<<"Is Given Tree a valid CBT : \n";
    checkCBT(root2)?cout<<"true":cout<<"false"<<endl;  

    return 0;
}